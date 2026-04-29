from enum import Enum
from typing import Optional

import rclpy
from rclpy.node import Node
from robot_msgs.msg import Context

GESTURE = "Open_Palm"

class State(Enum):
    SEARCH = 0
    TRACK = 1


class StateMachine:
    def __init__(self):
        self.state = State.SEARCH
        self.target_id: Optional[int] = None

        self.last_time: Optional[float] = None

        self.lost_target_timer = 0.0
        self.LOST_TIMEOUT = 3.0

        self.COOLDOWN = 3.0
        self.cooldown_timer = 0.0
        self.in_cooldown = False

        self.INCREASE_RATE = 1.0
        self.DECAY_RATE = 0.5
        self.TRACK_THRESHOLD = 3.0
        self.MAX_SCORE = 5.0

    def update(self, context: Context):
        now = context.header.stamp.sec + context.header.stamp.nanosec * 1e-9

        if self.last_time is None:
            self.last_time = now
            return ("SEARCH", None)

        dt = now - self.last_time
        self.last_time = now

        # cooldown countdown
        if self.in_cooldown:
            self.cooldown_timer -= dt
            if self.cooldown_timer <= 0:
                self.in_cooldown = False
            else:
                # skip all scoring during cooldown
                return (self.state.name, self.target_id)

        if self.state == State.SEARCH:
            return self._handle_search(context, dt)
        else:
            return self._handle_track(context, dt)

    def _handle_search(self, context, dt):
        visible_ids = {p.id for p in context.persons if p.visible}

        for person in context.persons:
            if not person.visible:
                continue

            score = person.palm_held_seconds

            if score >= self.TRACK_THRESHOLD:
                self.state = State.TRACK
                self.target_id = person.id
                self.in_cooldown = True
                self.cooldown_timer = self.COOLDOWN
                print(f"Tracking ID{self.target_id}!")
                return ("TRACK", person.id)

        return ("SEARCH", None)

    def _handle_track(self, context, dt):
        target = next((p for p in context.persons if p.id == self.target_id), None)

        # Handles lost targets
        if target is None or not target.visible:
            self.lost_target_timer += dt

            if self.lost_target_timer > self.LOST_TIMEOUT:
                print("Lost target → SEARCH")
                self._reset()
                return ("SEARCH", None)

            return ("TRACK", self.target_id)

        self.lost_target_timer = 0.0
        
        score = target.palm_held_seconds

        if score > self.TRACK_THRESHOLD:
            self._reset()
            print(f"Searching...")
            return ("SEARCH", None)

        return ("TRACK", target.id)

    def _reset(self):
        self.in_cooldown = True
        self.cooldown_timer = self.COOLDOWN
        self.state = State.SEARCH
        self.target_id = None


class StateMachineNode(Node):
    def __init__(self):
        super().__init__("state_machine")

        self.sm = StateMachine()

        self.subscription = self.create_subscription(
            Context,
            "context",
            self.callback,
            10,
        )

    def callback(self, msg: Context):
        state, target_id = self.sm.update(msg)