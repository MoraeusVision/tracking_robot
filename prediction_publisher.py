import os
from ultralytics import YOLO
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import String
from cv_bridge import CvBridge
import json


class PersonDetector:
    def __init__(self, engine_path, pt_path):
        if os.path.exists(engine_path):
            self.model = YOLO(engine_path)
        else:
            model = YOLO(pt_path)
            model.export(format="engine", half=True)
            self.model = YOLO(engine_path)

    def infer(self, frame):
        results = self.model.track(frame, persist=True, verbose=False)
        return results[0]


class PredictionPublisher(Node):
    def __init__(self, engine_path, pt_path):
        super().__init__("prediction_publisher")
        self.person_detector = PersonDetector(engine_path, pt_path)
        self.bridge = CvBridge()

        self.subscription = self.create_subscription(
            Image,
            "image_raw",
            self.image_callback,
            10,
        )

        self.prediction_pub = self.create_publisher(String, "predictions", 10)

    def image_callback(self, msg):
        frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")
        results = self.person_detector.infer(frame)
        boxes = results.boxes

        PERSON_CLASS_ID = 0  # COCO

        if boxes is not None and len(boxes) > 0:
            cls = boxes.cls.cpu().numpy()
            mask = cls == PERSON_CLASS_ID

            boxes_xyxy = boxes.xyxy.cpu().numpy()[mask].tolist()
            ids = boxes.id.cpu().numpy().astype(int)[mask].tolist() if boxes.id is not None else []
        else:
            boxes_xyxy = []
            ids = []

        payload = {
            "boxes_xyxy": boxes_xyxy,
            "ids": ids
        }

        out = String()
        out.data = json.dumps(payload)
        self.prediction_pub.publish(out)