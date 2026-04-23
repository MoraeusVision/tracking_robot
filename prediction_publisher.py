import os
from dataclasses import dataclass
from ultralytics import YOLO
from rclpy.node import Node


@dataclass
class Person:
    id: int
    bbox: tuple[float, float, float, float]
    last_seen: int

class PersonDetector():
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
    def __init__(self):
        super().__init__("predicction_publisher")
        self.publisher_ = self.create_publisher()