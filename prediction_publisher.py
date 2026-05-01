import os
import mediapipe as mp
import cv2
from mediapipe.tasks import python
from mediapipe.tasks.python import vision
from ultralytics import YOLO
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from robot_msgs.msg import Prediction, Person, Hand, Landmark


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
        print("Person detector initialized...")

    def infer(self, frame):
        """Run inference on a frame and return the first result object."""
        results = self.model.track(frame, persist=True, verbose=False)
        return results[0]

    def parse_persons(self, results):
        """Convert YOLO detections into a list of Person messages."""
        persons = []

        boxes = results.boxes
        if boxes is None:
            return persons

        for i in range(len(boxes)):
            # YOLO class 0 corresponds to person.
            if int(boxes.cls[i]) != 0:
                continue

            person_msg = Person()

            # ID
            if boxes.id is not None:
                person_msg.id = int(boxes.id[i])

            # Bounding box
            box = boxes.xyxy[i].cpu().tolist()
            person_msg.bbox_xyxy = [float(v) for v in box]

            persons.append(person_msg)

        return persons
                    

class HandDetector:
    """Recognize hand gestures and extract hand data from MediaPipe results."""

    def __init__(self, model_path):
        """Initialize the MediaPipe Gesture Recognizer with the given model file."""
        base_options = python.BaseOptions(model_asset_path=model_path)
        print("Hand detector initialized...")
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
        """Convert MediaPipe results to a list of Hand messages."""
        hands = []

        if not results.gestures:
            return hands

        for i in range(len(results.gestures)):
            gesture = results.gestures[i][0] if results.gestures[i] else None
            landmarks = results.hand_landmarks[i] if results.hand_landmarks else None

            if landmarks:
                cx, cy = self._get_hand_center(landmarks, frame)
            else:
                cx, cy = 0, 0

            hand_msg = Hand()
            hand_msg.gesture = gesture.category_name if gesture else ""
            hand_msg.center = [float(cx), float(cy)]
            if landmarks:
                for lm in landmarks:
                    lm_msg = Landmark()
                    lm_msg.x = float(lm.x)
                    lm_msg.y = float(lm.y)
                    lm_msg.z = float(lm.z)
                    hand_msg.landmarks.append(lm_msg)
            hands.append(hand_msg)

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

        self.prediction_pub = self.create_publisher(Prediction, "predictions", 10)

    def image_callback(self, msg):
        """Process an incoming frame and publish a Prediction ROS message."""
        frame = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

        person_results = self.person_detector.infer(frame)
        hand_results = self.hand_detector.infer(frame)
        
        hands = self.hand_detector.parse_hands(hand_results, frame)
        persons = self.person_detector.parse_persons(person_results)

        out = Prediction()

        out.header.stamp = msg.header.stamp
        out.header.frame_id = msg.header.frame_id
        out.frame = msg

        out.hands = hands
        out.persons = persons

        self.prediction_pub.publish(out)