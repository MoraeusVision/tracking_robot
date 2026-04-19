import cv2
import argparse
import logging
import supervision as sv
import torchvision.transforms as T
import torch
from PIL import Image

from typing import List, Any, Optional
from utils import get_device, parse_video_source
from inferencing import TRTInference, visualize_detections
from pipeline import CVPipeline

SOURCE = 0 #"examples/example1.mp4"
OUTPUT_PATH = "output/output.jpg"
ENGINE_PATH = "models/model.trt"



class RobotApp():
    def __init__(self, source: str, show: bool, save: bool, output_path: str, engine: str, device: str):
        self.source = parse_video_source(str(source))
        self.show = show
        self.save = save
        self.output_path = output_path
        self.engine = engine
        self.device = device

        if not torch.cuda.is_available():
            raise SystemExit("CUDA is not available. This script requires a GPU.")

        print("\n1. Initializing TRTInference...")
        self.trt_model = TRTInference(self.engine, device=self.device)

        self.pipeline = CVPipeline(
            source=self.source,
            on_frame=self.infer,
            on_prediction=self.on_prediction
        )
        
    def cleanup(self):
        if self.pipeline is not None:
            try:
                self.pipeline.stop()
            except Exception:
                pass


    def infer(self, frame):
        # BGR -> RGB + numpy -> PIL
        #image = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        #image_pil = Image.fromarray(image)
        image_pil = Image.open("examples/bear.jpeg").convert('RGB')
        w, h = image_pil.size

        transforms = T.Compose([
            T.Resize((640, 640)),
            T.ToTensor(),
        ])

        image_tensor = transforms(image_pil).unsqueeze(0).to(self.device)
        orig_size_tensor = torch.tensor([[w, h]], dtype=torch.int64, device=self.device)

        blob = {
            'images': image_tensor,
            'orig_target_sizes': orig_size_tensor
        }

        output_gpu = self.trt_model(blob)
        torch.cuda.synchronize()

        output_labels = output_gpu['labels'][0]
        output_boxes = output_gpu['boxes'][0]
        output_scores = output_gpu['scores'][0]

        print(f"labels: {output_labels}")
        print(f"boxes: {output_boxes}")
        print(f"scores: {output_scores}")

        result_image = visualize_detections(
            image_pil, 
            output_boxes, 
            output_scores, 
            output_labels, 
            threshold=0.1
        )
        
        result_image.save(self.output_path)
        


        return {"dummy": True}

    def on_prediction(self, frame, prediction):
        
        return None

    def run(self):
        try:
            self.pipeline.run()
        finally:
            self.cleanup()
        


def parse_args():
    parser = argparse.ArgumentParser(description="Detection App")

    parser.add_argument("--source", type=str, default=SOURCE)
    parser.add_argument("--output_path", type=str, default=OUTPUT_PATH)
    parser.add_argument('--engine', type=str, default=ENGINE_PATH, help="Path to the TensorRT engine file.")
    parser.add_argument("--show", action="store_true", default=False)
    parser.add_argument("--save", action="store_true", default=False)
    parser.add_argument('--device', type=str, default='cuda:0', help="Device to run inference on.")

    return parser.parse_args()

if __name__ == "__main__":
    args = parse_args()

    app = None
    try:
        app = RobotApp(
            source=args.source,
            show=args.show,
            save=args.save,
            output_path=args.output_path,
            engine=args.engine,
            device=args.device,
        )
        app.run()
    finally:
        if app is not None:
            app.cleanup()