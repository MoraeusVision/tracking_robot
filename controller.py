
from rclpy.node import Node
from robot_msgs.msg import RobotState


class ControllerNode(Node):
    def __init__(self, frame_width):
        super().__init__("controller")
        self.frame_width = float(frame_width) if frame_width else 1.0

        self.subscription = self.create_subscription(
            RobotState,
            "robot_state",
            self.callback,
            10,
        )

    def callback(self, msg):
        if msg.tracked_id == -1:
            return

        bbox = msg.target_bbox
        x1, _, x2, _ = bbox
        center_x = (x1 + x2) / 2.0
        center_x_norm = center_x / self.frame_width