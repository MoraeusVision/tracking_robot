import cv2
import argparse
import logging
import supervision as sv

from typing import List, Any, Optional
from inference.core.interfaces.camera.entities import VideoFrame
from inference import InferencePipeline
from utils import get_device, parse_video_source

VIDEO_PATH = "examples/example1.mp4"
OUTPUT_PATH = "output/output.mp4"


class RobotApp():
    def __init__(self, source, show, save):
        self.source = source
        self.show = show
        self.save = save

    def run(self):
        print("hej")


def parse_args():
    parser = argparse.ArgumentParser(description="Detection App")

    parser.add_argument("--source", type=str, default=VIDEO_PATH)
    
    parser.add_argument("--show", action="store_true", default=False)
    parser.add_argument("--save", action="store_true", default=False)

    return parser.parse_args()

if __name__ == "__main__":
    args = parse_args()

    app = RobotApp(
        source=args.source,
        show=args.show,
        save=args.save
    )
    app.run()