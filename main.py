import argparse
import os

from pipeline import CVPipeline
import rclpy
from rclpy.executors import MultiThreadedExecutor
from frame_publisher import FramePublisher
from prediction_publisher import PredictionPublisher


SOURCE = 0 #"examples/example1.mp4"
OUTPUT_PATH = "output/output.mp4"
ENGINE_PATH = "models/yolo26n.engine"
MP_PATH = "models/gesture_recognizer.task"
PT_PATH = "models/yolo26n.pt"
FRAMES_TO_FORGET = 30




class Robot():
    def __init__(self, source, engine_path, pt_path):
        self.source = source
        self.person_detector = PersonDetector(engine_path, pt_path)
        self.pipeline = CVPipeline(source, self.on_frame, self.on_prediction)
        self.persons = {}
        self.frame_id = 0
    
    def on_frame(self, frame):
        person_results = self.person_detector.infer(frame)
        return person_results

    def on_prediction(self, frame, prediction):
        boxes = prediction.boxes
        track_ids = boxes.id.int().cpu().tolist() if boxes.id is not None else [None] * len(boxes)

        seen_ids = set()

        for i, box in enumerate(boxes):
            if int(box.cls[0]) != 0:
                continue

            track_id = track_ids[i]
            if track_id is None:
                continue

            x1, y1, x2, y2 = box.xyxy[0].tolist()

            person = Person(id=int(track_id), bbox=(x1, y1, x2, y2), last_seen=self.frame_id)
            self.persons[person.id] = person
            seen_ids.add(person.id)

        print(self.persons)

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

def main(args=None):
    rclpy.init(args=args)

    image_publisher = FramePublisher()
    prediction_publisher = PredictionPublisher(ENGINE_PATH, PT_PATH, MP_PATH)

    executor = MultiThreadedExecutor()
    executor.add_node(image_publisher)
    executor.add_node(prediction_publisher)

    executor.spin()

    image_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()