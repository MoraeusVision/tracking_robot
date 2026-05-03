from enum import Enum
from typing import Optional

import rclpy
from rclpy.node import Node
from robot_msgs.msg import Context, RobotState

GESTURE = "Open_Palm"

class State(Enum):
    SEARCH = 0
    TRACK = 1


class StateMachine():
    def __init__(self):
        self.state = State.SEARCH
        self.target_id: Optional[int] = None
        self.target_bbox: list[float] = [0.0, 0.0, 0.0, 0.0]

        self.last_time: Optional[float] = None

        self.lost_target_timer = 0.0
        self.LOST_TIMEOUT = 3.0

        self.INCREASE_RATE = 1.0
        self.DECAY_RATE = 0.5
        self.TRACK_THRESHOLD = 3.0
        self.MAX_SCORE = 5.0

    def update(self, context: Context):
        prev_state = self.state

        now = context.header.stamp.sec + context.header.stamp.nanosec * 1e-9

        if self.last_time is None:
            self.last_time = now
            return False

        dt = now - self.last_time
        self.last_time = now

        if self.state == State.SEARCH:
            self._handle_search(context)
        else:
            self._handle_track(context, dt)

        state_changed = (self.state != prev_state)

        return state_changed

    def _handle_search(self, context):
        for person in context.persons:
            if not person.visible:
                continue

            score = person.palm_held_seconds

            if score >= self.TRACK_THRESHOLD:
                self.state = State.TRACK
                self.target_id = person.id
                self.target_bbox = [float(v) for v in person.bbox_xyxy]
                print(f"Tracking ID{self.target_id}!")
                return

    def _handle_track(self, context, dt):
        target = next((p for p in context.persons if p.id == self.target_id), None)

        # Handles lost targets
        if target is None or not target.visible:
            self.lost_target_timer += dt

            if self.lost_target_timer > self.LOST_TIMEOUT:
                print("Lost target → SEARCH")
                self._reset()
                return

            return

        self.lost_target_timer = 0.0
        self.target_bbox = list(target.bbox_xyxy)

        score = target.palm_held_seconds

        if score > self.TRACK_THRESHOLD:
            self._reset()
            print(f"Searching...")
            return

    def _reset(self):
        self.state = State.SEARCH
        self.target_id = None
        self.target_bbox = [0.0, 0.0, 0.0, 0.0]


class StateMachineNode(Node):
    def __init__(self):
        super().__init__("robot_state")

        self.sm = StateMachine()

        self.subscription = self.create_subscription(
            Context,
            "context",
            self.callback,
            10,
        )

        self.publisher = self.create_publisher(
            RobotState,
            "robot_state",
            10,
        )

    def callback(self, msg: Context):
        changed = self.sm.update(msg)

        out = RobotState()
        out.state_changed = changed
        out.tracked_id = self.sm.target_id if self.sm.target_id is not None else -1
        out.target_bbox = [float(v) for v in self.sm.target_bbox]

        self.publisher.publish(out)