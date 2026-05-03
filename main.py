import argparse
import rclpy
from rclpy.executors import MultiThreadedExecutor
from frame_publisher import FramePublisher
from prediction_publisher import PredictionPublisher
from context_publisher import ContextPublisher
from state_machine import StateMachineNode
from controller import ControllerNode
from visualization import VisualizationNode

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
    context_publisher = ContextPublisher()
    state_machine_node = StateMachineNode()
    _, frame_width = image_publisher.get_shape()
    controller_node = ControllerNode(frame_width)
    visualization_node = VisualizationNode(OUTPUT_PATH)
    
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
        prediction_publisher.destroy_node()
        image_publisher.destroy_node()
        controller_node.destroy_node()
        visualization_node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()