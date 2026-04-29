from dataclasses import dataclass
from typing import Dict, Optional

from rclpy.node import Node
from robot_msgs.msg import (
    Context,
    HandState as HandStateMsg,
    PersonState as PersonStateMsg,
    Prediction, RobotState
)

SECONDS_TO_FORGET = 2
GESTURE = "Open_Palm"


@dataclass
class PersonState:
    id: int
    bbox_xyxy: tuple[float, float, float, float]
    last_seen: float
    tracked: bool = False
    palm_held_time: float = 0.0
    visible: bool = True


class PersonManager:
    def __init__(self):
        self.people: Dict[int, PersonState] = {}

        # scoring params
        self.INCREASE_RATE = 1.0
        self.DECAY_RATE = 0.5
        self.MAX_SCORE = 5.0

        self.last_time: Optional[float] = None

    def update(self, persons_msg, hands_msg, now: float):
        # --- dt ---
        if self.last_time is None:
            self.last_time = now
            dt = 0.0
        else:
            dt = now - self.last_time
            self.last_time = now

        present_ids = set()

        # --- update / create persons ---
        for p in persons_msg:
            person_id = int(p.id)
            bbox = tuple(float(v) for v in p.bbox_xyxy)
            present_ids.add(person_id)

            if person_id in self.people:
                person = self.people[person_id]
                person.bbox_xyxy = bbox
                person.last_seen = now
                person.visible = True
            else:
                self.people[person_id] = PersonState(
                    id=person_id,
                    bbox_xyxy=bbox,
                    last_seen=now,
                    visible=True,
                )

        # --- mark invisible ---
        for person_id, person in self.people.items():
            if person_id not in present_ids:
                person.visible = False

        # --- scoring ---
        for person in self.people.values():
            if not person.visible:
                continue

            has_open_palm = any(
                h.owner == person.id and h.gesture == GESTURE
                for h in hands_msg
            )

            if has_open_palm:
                person.palm_held_time += self.INCREASE_RATE * dt
            else:
                person.palm_held_time -= self.DECAY_RATE * dt
            
            person.palm_held_time = max(0.0, min(self.MAX_SCORE, person.palm_held_time))
            if person.palm_held_time > 0:
                print(f"{person.id}: {person.palm_held_time}")

        # --- remove old ---
        to_remove = []
        for person_id, person in self.people.items():
            if now - person.last_seen > SECONDS_TO_FORGET:
                to_remove.append(person_id)

        for person_id in to_remove:
            del self.people[person_id]

        # --- build msgs ---
        person_states: list[PersonStateMsg] = []
        for state in self.people.values():
            person_msg = PersonStateMsg()
            person_msg.id = state.id
            person_msg.bbox_xyxy = [float(v) for v in state.bbox_xyxy]
            person_msg.last_seen = int(state.last_seen)
            person_msg.tracked = state.tracked
            person_msg.palm_held_seconds = state.palm_held_time
            person_msg.visible = state.visible
            person_states.append(person_msg)

        return person_states



class HandManager:
    def __init__(self):
        self.hands: list[HandStateMsg] = []

    @staticmethod
    def _point_inside_bbox(x: float, y: float, bbox_xyxy: tuple[float, float, float, float]) -> bool:
        x1, y1, x2, y2 = bbox_xyxy
        return x1 <= x <= x2 and y1 <= y <= y2

    def update(self, hands_msg, persons: Dict[int, PersonState]):
        hand_states: list[HandStateMsg] = []

        for hand in hands_msg:
            cx = float(hand.center[0]) if len(hand.center) > 0 else 0.0
            cy = float(hand.center[1]) if len(hand.center) > 1 else 0.0

            owner = -1

            for person in persons.values():
                if not person.visible:
                    continue

                if self._point_inside_bbox(cx, cy, person.bbox_xyxy):
                    owner = int(person.id)
                    break

            hand_state_msg = HandStateMsg()
            hand_state_msg.owner = owner
            hand_state_msg.gesture = hand.gesture
            hand_state_msg.center = [cx, cy]
            hand_state_msg.landmarks = hand.landmarks
            hand_states.append(hand_state_msg)

        self.hands = hand_states
        return hand_states


class ContextPublisher(Node):
    def __init__(self):
        super().__init__("context_publisher")
        self.person_manager = PersonManager()
        self.hand_manager = HandManager()
        self.context_publisher = self.create_publisher(Context, "context", 10)

        self.subscription = self.create_subscription(
            Prediction,
            "predictions",
            self.context_callback,
            10,
        )

        self.state_subscription = self.create_subscription(
            RobotState,
            "robot_state",
            self.state_callback,
            10,
        )

    def context_callback(self, msg):
        persons = msg.persons
        hands = msg.hands
        now = float(msg.header.stamp.sec) + float(msg.header.stamp.nanosec) * 1e-9

        hand_states = self.hand_manager.update(hands, self.person_manager.people)
        person_states = self.person_manager.update(persons, hand_states, now)
        

        out = Context()
        out.header.stamp = msg.header.stamp
        out.header.frame_id = msg.header.frame_id

        out.persons = person_states

        out.hands = hand_states

        self.context_publisher.publish(out)

    def state_callback(self, msg):
        print(msg)
        if msg.state_changed:
            for person in self.person_manager.people.values():
                person.palm_held_time = 0.0