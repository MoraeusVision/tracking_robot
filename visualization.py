import cv2
import numpy as np
import rclpy
import supervision as sv
from cv_bridge import CvBridge
from rclpy.node import Node
from robot_msgs.msg import Context
from sensor_msgs.msg import Image

OUTPUT_PATH = "output/output.mp4"
FPS = 30.0


class VisualizationNode(Node):
    def __init__(self, output_path: str = OUTPUT_PATH):
        super().__init__("visualization")

        self.bridge = CvBridge()
        self.latest_image = None
        self.latest_context = None
        self.output_path = output_path
        self.video_writer = None
        self.box_annotator = sv.BoxAnnotator()

        self.create_subscription(Context, "context", self.context_callback, 10)
        self.create_subscription(Image, "image_raw", self.image_callback, 10)

        # Render in a fixed-rate loop instead of drawing from message callbacks.
        self.create_timer(1.0 / FPS, self.render_callback)

    def context_callback(self, msg: Context):
        if msg is not None:
            self.latest_context = msg

    def image_callback(self, msg: Image):
        if msg is not None:
            self.latest_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

    def render_callback(self):
        if self.latest_image is None:
            return

        frame = self.latest_image.copy()

        if self.latest_context is not None:
            persons = self.latest_context.persons
            if persons:
                xyxy = np.array([p.bbox_xyxy for p in persons], dtype=np.float32)
                class_ids = np.zeros(len(xyxy), dtype=int)
                detections = sv.Detections(xyxy=xyxy, class_id=class_ids)
                frame = self.box_annotator.annotate(frame, detections)

        if self.video_writer is None:
            h, w = frame.shape[:2]
            fourcc = cv2.VideoWriter_fourcc(*"mp4v")
            self.video_writer = cv2.VideoWriter(self.output_path, fourcc, FPS, (w, h))
            self.get_logger().info(f"Saving video to {self.output_path}")

        self.video_writer.write(frame)

    def destroy_node(self):
        if self.video_writer is not None:
            self.video_writer.release()
            self.get_logger().info(f"Video saved to {self.output_path}")
        super().destroy_node()