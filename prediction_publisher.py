import os
import mediapipe as mp
import cv2
from mediapipe.tasks import python
from mediapipe.tasks.python import vision
from ultralytics import YOLO
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import String
from cv_bridge import CvBridge
import json


class PersonDetector:
    """Handle person detection and tracking with YOLO."""

    def __init__(self, engine_path, pt_path):
        """Load a TensorRT engine if available, otherwise export it from .pt."""
        if os.path.exists(engine_path):
            self.model = YOLO(engine_path)
        else:
            model = YOLO(pt_path)
            model.export(format="engine", half=True)
            self.model = YOLO(engine_path)

    def infer(self, frame):
        """Run inference on a frame and return the first result object."""
        results = self.model.track(frame, persist=True, verbose=False)
        return results[0]
    

class HandDetector:
    """Recognize hand gestures and extract hand data from MediaPipe results."""

    def __init__(self, model_path):
        """Initialize the MediaPipe Gesture Recognizer with the given model file."""
        base_options = python.BaseOptions(model_asset_path=model_path)
        options = vision.GestureRecognizerOptions(
            base_options=base_options,
            num_hands=2)
        self.recognizer = vision.GestureRecognizer.create_from_options(options)

    def infer(self, frame):
        """Run gesture recognition on a frame and return raw MediaPipe results."""
        rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        image = mp.Image(
            image_format=mp.ImageFormat.SRGB,
            data=rgb_frame
        )
        results = self.recognizer.recognize(image)
        return results

    def parse_hands(self, results, frame):
        """Convert MediaPipe results to a simple list with gesture and hand center."""
        hands = []

        if not results.gestures:
            return hands

        for i in range(len(results.gestures)):
            gesture = results.gestures[i][0] if results.gestures[i] else None
            landmarks = results.hand_landmarks[i] if results.hand_landmarks else None

            if landmarks:
                cx, cy = self._get_hand_center(landmarks, frame)
            else:
                cx, cy = None, None

            hands.append({
                "gesture": gesture.category_name if gesture else None,
                "center": [cx, cy]
            })

        return hands
    
    def _get_hand_center(self, hand_landmarks, frame):
        """Compute the hand center in pixel coordinates from landmarks."""
        h, w, _ = frame.shape

        xs = [lm.x for lm in hand_landmarks]
        ys = [lm.y for lm in hand_landmarks]

        center_x = int((sum(xs) / len(xs)) * w)
        center_y = int((sum(ys) / len(ys)) * h)

        return center_x, center_y


class PredictionPublisher(Node):
    """ROS2 node that reads camera frames and publishes person and hand predictions."""

    def __init__(self, engine_path, pt_path, mp_path):
        """Create detectors, image subscription, and prediction publisher."""
        super().__init__("prediction_publisher")
        self.person_detector = PersonDetector(engine_path, pt_path)
        self.hand_detector = HandDetector(mp_path)
        self.bridge = CvBridge()

        self.subscription = self.create_subscription(
            Image,
            "image_raw",
            self.image_callback,
            10,
        )

        self.prediction_pub = self.create_publisher(String, "predictions", 10)

    def image_callback(self, msg):
        """Process an incoming frame and publish a JSON payload with results."""
        frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")
        person_results = self.person_detector.infer(frame)
        hand_results = self.hand_detector.infer(frame)
        
        hands = self.hand_detector.parse_hands(hand_results, frame)
        boxes = person_results.boxes

        if boxes is not None and len(boxes) > 0:
            cls = boxes.cls.cpu().numpy()
            mask = cls == 0 # Person class

            boxes_xyxy = boxes.xyxy.cpu().numpy()[mask].tolist()
            ids = boxes.id.cpu().numpy().astype(int)[mask].tolist() if boxes.id is not None else []
        else:
            boxes_xyxy = []
            ids = []

        payload = {
            "boxes_xyxy": boxes_xyxy,
            "ids": ids,
            "hands": hands
        }

        out = String()
        out.data = json.dumps(payload)
        self.prediction_pub.publish(out)