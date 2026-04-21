import argparse
import os
from dataclasses import dataclass
from ultralytics import YOLO
from pipeline import CVPipeline


SOURCE = 0 #"examples/example1.mp4"
OUTPUT_PATH = "output/output.mp4"
ENGINE_PATH = "models/yolo26n.engine"
PT_PATH = "models/yolo26n.pt"

@dataclass
class Person:
    id: int
    bbox: tuple[float, float, float, float]

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


class Robot():
    def __init__(self, source, engine_path, pt_path):
        self.source = source
        self.person_detector = PersonDetector(engine_path, pt_path)
        self.pipeline = CVPipeline(source, self.on_frame, self.on_prediction)
        self.persons = []
    
    def on_frame(self, frame):
        person_results = self.person_detector.infer(frame)
        return person_results

    def on_prediction(self, frame, prediction):
        persons = []
        boxes = prediction.boxes
        track_ids = boxes.id.int().cpu().tolist() if boxes.id is not None else [None] * len(boxes)

        for i, box in enumerate(boxes):
            if int(box.cls[0]) != 0:
                continue

            x1, y1, x2, y2 = box.xyxy[0].tolist()
            track_id = track_ids[i]
            if track_id is None:
                continue

            persons.append(Person(id=int(track_id), bbox=(x1, y1, x2, y2)))

        self.persons = persons
        print(f"persons: {self.persons}")

    def run(self):
        try:
            self.pipeline.run()
        finally:
            self.pipeline.stop()

    def cleanup(self):
        pass


def parse_args():
    parser = argparse.ArgumentParser(description="Robot App")

    parser.add_argument("--source", type=str, default=SOURCE)
    parser.add_argument("--output_path", type=str, default=OUTPUT_PATH)
    parser.add_argument('--engine', type=str, default=ENGINE_PATH, help="Path to the TensorRT engine file.")
    parser.add_argument('--pt', type=str, default=PT_PATH, help="Path to the PyTorch model file.")
    parser.add_argument("--show", action="store_true", default=False)
    parser.add_argument("--save", action="store_true", default=False)
    
    return parser.parse_args()

if __name__ == "__main__":
    args = parse_args()

    app = None
    try:
        app = Robot(
            source=args.source,
            engine_path=args.engine,
            pt_path=args.pt
        )
        app.run()
    finally:
        if app is not None:
            app.cleanup()