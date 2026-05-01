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
        self.label_annotator = sv.LabelAnnotator()

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
            hands = self.latest_context.hands
            if persons:
                tracked_person = next((p for p in persons if p.tracked), None)

                # Only visualize the tracked person
                if tracked_person is not None:
                    xyxy = np.array([tracked_person.bbox_xyxy], dtype=np.float32)
                    class_ids = np.array([0], dtype=int)
                    labels = ["Tracked!"]

                    detections = sv.Detections(xyxy=xyxy, class_id=class_ids)
                    frame = self.box_annotator.annotate(frame, detections)
                    frame = self.label_annotator.annotate(frame, detections, labels=labels)
                else:     
                    xyxy = np.array([p.bbox_xyxy for p in persons], dtype=np.float32)
                    class_ids = np.zeros(len(xyxy), dtype=int)
                    detections = sv.Detections(xyxy=xyxy, class_id=class_ids)
                    frame = self.box_annotator.annotate(frame, detections)

            if hands:
                HAND_CONNECTIONS = [
                    (0, 1), (1, 2), (2, 3), (3, 4),
                    (0, 5), (5, 6), (6, 7), (7, 8),
                    (0, 9), (9, 10), (10, 11), (11, 12),
                    (0, 13), (13, 14), (14, 15), (15, 16),
                    (0, 17), (17, 18), (18, 19), (19, 20),
                    (5, 9), (9, 13), (13, 17),
                ]
                h_img, w_img = frame.shape[:2]
                for hand in hands:
                    pts = [(int(lm.x * w_img), int(lm.y * h_img)) for lm in hand.landmarks]
                    for a, b in HAND_CONNECTIONS:
                        if a < len(pts) and b < len(pts):
                            cv2.line(frame, pts[a], pts[b], (0, 255, 0), 1)
                    for pt in pts:
                        cv2.circle(frame, pt, 2, (0, 200, 255), -1)

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