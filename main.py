import argparse
import rclpy
from rclpy.executors import MultiThreadedExecutor
from frame_publisher import FramePublisher
from prediction_publisher import PredictionPublisher
from context_publisher import ContextPublisher
from state_machine import StateMachineNode
from controller import ControllerNode
from visualization import VisualizationNode
from runtime_config import RuntimeTuningStore
from web_dashboard import TuningWebApp

SOURCE = 0 #"examples/example1.mp4"
OUTPUT_PATH = "output/output.mp4"
ENGINE_PATH = "models/yolo26n.engine"
MP_PATH = "models/gesture_recognizer.task"
PT_PATH = "models/yolo26n.pt"
FRAMES_TO_FORGET = 30
WEB_HOST = "0.0.0.0"
WEB_PORT = 8000



def parse_args(argv=None):
    parser = argparse.ArgumentParser(description="Robot App")

    parser.add_argument("--source", default=SOURCE, help="Camera index or video path.")
    parser.add_argument("--output_path", type=str, default=OUTPUT_PATH)
    parser.add_argument('--engine', type=str, default=ENGINE_PATH, help="Path to the TensorRT engine file.")
    parser.add_argument('--pt', type=str, default=PT_PATH, help="Path to the PyTorch model file.")
    parser.add_argument("--web_host", type=str, default=WEB_HOST)
    parser.add_argument("--web_port", type=int, default=WEB_PORT)
    parser.add_argument("--show", action="store_true", default=False)
    parser.add_argument("--save", action="store_true", default=False)
    
    return parser.parse_args(argv)


def _coerce_source(source):
    if isinstance(source, int):
        return source

    if isinstance(source, str):
        stripped = source.strip()
        if stripped.isdigit():
            return int(stripped)

    return source

def main(args=None):
    rclpy.init(args=args)
    parsed_args = parse_args(args)

    tuning_store = RuntimeTuningStore()
    web_app = TuningWebApp(parsed_args.web_host, parsed_args.web_port, tuning_store)
    web_app.start()

    image_publisher = FramePublisher(_coerce_source(parsed_args.source))
    prediction_publisher = PredictionPublisher(parsed_args.engine, parsed_args.pt, MP_PATH)
    context_publisher = ContextPublisher()
    state_machine_node = StateMachineNode()
    _, frame_width = image_publisher.get_shape()
    controller_node = ControllerNode(frame_width, tuning_store)
    visualization_node = VisualizationNode(parsed_args.output_path, tuning_store)
    
    executor = MultiThreadedExecutor()
    executor.add_node(image_publisher)
    executor.add_node(prediction_publisher)
    executor.add_node(context_publisher)
    executor.add_node(state_machine_node)
    executor.add_node(controller_node)
    executor.add_node(visualization_node)

    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        executor.shutdown()
        web_app.stop()
        prediction_publisher.destroy_node()
        image_publisher.destroy_node()
        controller_node.destroy_node()
        visualization_node.destroy_node()


if __name__ == "__main__":
    main()