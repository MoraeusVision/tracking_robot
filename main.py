import argparse
import os
import sys

import cv2
import numpy as np
import tensorrt as trt
import torch

WORKSPACE_ROOT = os.path.dirname(os.path.abspath(__file__))
YOLOX_ROOT = os.path.join(WORKSPACE_ROOT, "YOLOX")

if YOLOX_ROOT not in sys.path:
    sys.path.insert(0, YOLOX_ROOT)

from YOLOX.tools.demo import Predictor
from utils import parse_video_source
from pipeline import CVPipeline
from yolox.data.data_augment import ValTransform
from yolox.data.datasets import COCO_CLASSES
from yolox.utils import postprocess

SOURCE = 0 #"examples/example1.mp4"
OUTPUT_PATH = "output/output.jpg"
ENGINE_PATH = "models/model_trt.engine"


class EnginePredictor:
    def __init__(self, engine_path, cls_names=COCO_CLASSES, device="gpu", fp16=False, legacy=False):
        if device != "gpu":
            raise ValueError("TensorRT engine inference requires device='gpu'.")
        if not os.path.exists(engine_path):
            raise FileNotFoundError(f"TensorRT engine not found: {engine_path}")

        self.engine_path = engine_path
        self.cls_names = cls_names
        self.device = device
        self.fp16 = fp16
        self.preproc = ValTransform(legacy=legacy)
        self.logger = trt.Logger(trt.Logger.WARNING)
        self.runtime = trt.Runtime(self.logger)

        with open(engine_path, "rb") as engine_file:
            self.engine = self.runtime.deserialize_cuda_engine(engine_file.read())

        if self.engine is None:
            raise RuntimeError(f"Failed to deserialize TensorRT engine: {engine_path}")

        self.context = self.engine.create_execution_context()
        self.input_name, self.output_name = self._get_io_names()
        self.input_shape = tuple(self.engine.get_tensor_shape(self.input_name))
        self.output_shape = tuple(self.engine.get_tensor_shape(self.output_name))
        self.test_size = (int(self.input_shape[2]), int(self.input_shape[3]))
        self.num_classes = int(self.output_shape[2] - 5)
        self.confthre = 0.3
        self.nmsthre = 0.3
        self._allocate_buffers()

    def _get_io_names(self):
        input_name = None
        output_name = None

        for index in range(self.engine.num_io_tensors):
            tensor_name = self.engine.get_tensor_name(index)
            tensor_mode = self.engine.get_tensor_mode(tensor_name)
            if tensor_mode == trt.TensorIOMode.INPUT:
                input_name = tensor_name
            elif tensor_mode == trt.TensorIOMode.OUTPUT:
                output_name = tensor_name

        if input_name is None or output_name is None:
            raise RuntimeError("TensorRT engine must expose exactly one input and one output tensor.")

        return input_name, output_name

    def _allocate_buffers(self):
        input_dtype = self._torch_dtype(self.engine.get_tensor_dtype(self.input_name))
        output_dtype = self._torch_dtype(self.engine.get_tensor_dtype(self.output_name))
        self.input_tensor = torch.empty(self.input_shape, dtype=input_dtype, device="cuda")
        self.output_tensor = torch.empty(self.output_shape, dtype=output_dtype, device="cuda")

    @staticmethod
    def _torch_dtype(dtype):
        dtype_map = {
            trt.DataType.FLOAT: torch.float32,
            trt.DataType.HALF: torch.float16,
            trt.DataType.INT32: torch.int32,
            trt.DataType.INT8: torch.int8,
            trt.DataType.BOOL: torch.bool,
        }
        if dtype not in dtype_map:
            raise TypeError(f"Unsupported TensorRT dtype: {dtype}")
        return dtype_map[dtype]

    def inference(self, img):
        img_info = {"id": 0}
        if isinstance(img, str):
            img_info["file_name"] = os.path.basename(img)
            img = cv2.imread(img)
        else:
            img_info["file_name"] = None

        height, width = img.shape[:2]
        img_info["height"] = height
        img_info["width"] = width
        img_info["raw_img"] = img

        ratio = min(self.test_size[0] / img.shape[0], self.test_size[1] / img.shape[1])
        img_info["ratio"] = ratio

        image, _ = self.preproc(img, None, self.test_size)
        image = np.ascontiguousarray(image, dtype=np.float32)
        if self.input_tensor.dtype == torch.float16:
            image = image.astype(np.float16)

        image_tensor = torch.from_numpy(image).unsqueeze(0).to(device="cuda", non_blocking=True)
        self.input_tensor.copy_(image_tensor)

        stream = torch.cuda.current_stream().cuda_stream
        self.context.set_tensor_address(self.input_name, self.input_tensor.data_ptr())
        self.context.set_tensor_address(self.output_name, self.output_tensor.data_ptr())
        self.context.execute_async_v3(stream_handle=stream)
        torch.cuda.current_stream().synchronize()

        outputs = postprocess(
            self.output_tensor.unsqueeze(0) if self.output_tensor.ndim == 2 else self.output_tensor,
            self.num_classes,
            self.confthre,
            self.nmsthre,
            class_agnostic=True,
        )
        return outputs, img_info

    def visual(self, output, img_info, cls_conf=0.35):
        return Predictor.visual(self, output, img_info, cls_conf)



class RobotApp():
    def __init__(
        self,
        source: str,
        show: bool,
        save: bool,
        output_path: str,
        engine: str,
        device: str,
    ):
        self.source = parse_video_source(str(source))
        self.show = show
        self.save = save
        self.output_path = output_path
        self.engine = engine
        self.device = device
        self.frame_id = 0

        if not torch.cuda.is_available():
            raise SystemExit("CUDA is not available. This script requires a GPU.")

        self.predictor = self._build_predictor()

        self.pipeline = CVPipeline(
            source=self.source,
            on_frame=self.infer,
            on_prediction=self.on_prediction
        )

    def _build_predictor(self):
        return EnginePredictor(
            engine_path=self.engine,
            cls_names=COCO_CLASSES,
            device="gpu",
        )
        
    def cleanup(self):
        if self.pipeline is not None:
            try:
                self.pipeline.stop()
            except Exception:
                pass


    def infer(self, frame):
        outputs, img_info = self.predictor.inference(frame)
        print(f"frame: {self.frame_id}, detections: {outputs is not None and outputs[0] is not None}")
        self.frame_id += 1
        return outputs, img_info

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
            device=args.device
        )
        app.run()
    finally:
        if app is not None:
            app.cleanup()