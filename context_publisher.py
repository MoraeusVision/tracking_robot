from rclpy.node import Node
from robot_msgs.msg import Prediction, Context, Person
from dataclasses import dataclass
from typing import Dict

TIME_TO_FORGET = 3

@dataclass
class PersonState:
    id: int
    bbox_xyxy: tuple[float, float, float, float]
    last_seen: int
    tracked: bool = False
    palm_held_seconds: int = 0
    visible: bool = True


class PersonManager:
    def __init__(self):
        self.people: Dict[int, PersonState] = {}

    def update(self, persons_msg, stamp_sec: int):

        for p in persons_msg:
            person_id = int(p.id)
            bbox = tuple(float(v) for v in p.bbox_xyxy)

            if person_id in self.people:
                person = self.people[person_id]
                person.bbox_xyxy = bbox
                person.last_seen = stamp_sec
            else:
                self.people[person_id] = PersonState(
                    id=person_id,
                    bbox_xyxy=bbox,
                    last_seen=stamp_sec,
                )

        to_remove = []
        for person_id, person in self.people.items():
            if stamp_sec - person.last_seen > TIME_TO_FORGET:
                to_remove.append(person_id)

        for person_id in to_remove:
            del self.people[person_id]

        return self.people


class ContextPublisher(Node):
    def __init__(self):
        super().__init__("context_publisher")
        self.person_manager = PersonManager()
        self.context_publisher = self.create_publisher(Context, "context", 10)

        self.subscription = self.create_subscription(
            Prediction,
            "predictions",
            self.context_callback,
            10,
        )

    def context_callback(self, msg):
        persons = msg.persons
        stamp_sec = int(msg.header.stamp.sec)
        person_states = self.person_manager.update(persons, stamp_sec)

        out = Context()
        out.header.stamp = msg.header.stamp
        out.header.frame_id = msg.header.frame_id

        out.persons = []
        for state in person_states.values():
            person_msg = Person()
            person_msg.id = state.id
            person_msg.bbox_xyxy = [float(v) for v in state.bbox_xyxy]
            out.persons.append(person_msg)

        self.context_publisher.publish(out)
