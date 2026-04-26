import argparse
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

    image_publisher = FramePublisher(SOURCE)
    prediction_publisher = PredictionPublisher(ENGINE_PATH, PT_PATH, MP_PATH)

    executor = MultiThreadedExecutor()
    executor.add_node(image_publisher)
    executor.add_node(prediction_publisher)

    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        executor.shutdown()
        prediction_publisher.destroy_node()
        image_publisher.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()