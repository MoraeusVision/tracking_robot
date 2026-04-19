import cv2
import time
import logging
import multiprocessing as mp


QUEUE_SIZE = 5

logging.basicConfig(level=logging.INFO)

def capture_worker(source, queue, stop_event, reconnect_delay):
    cap = None

    def connect():
        nonlocal cap
        logging.info(f"[Capture] Connecting to {source}")
        cap = cv2.VideoCapture(source)
        return cap.isOpened()

    def reconnect():
        nonlocal cap
        if cap:
            cap.release()
        time.sleep(reconnect_delay)
        return connect()

    if not connect():
        while not stop_event.is_set() and not reconnect():
            pass

    while not stop_event.is_set():
        ret, frame = cap.read()

        if not ret or frame is None:
            logging.warning("[Capture] Frame failed")
            reconnect()
            continue

        # Drop frame if queue is full (real-time > latency)
        if not queue.full():
            queue.put(frame)
        else:
            try:
                queue.get_nowait()  # remove oldest
                queue.put(frame)
            except:
                pass

    if cap:
        cap.release()
    logging.info("[Capture] Stopped")


class CVPipeline:
    def __init__(self, source, on_frame, on_prediction=None, queue_size=QUEUE_SIZE):
        if not callable(on_frame):
            raise ValueError("on_frame must be callable")

        self.source = source
        self.on_frame = on_frame
        self.on_prediction = on_prediction

        self.queue = mp.Queue(maxsize=queue_size)
        self.stop_event = mp.Event()
        self.process = None

    def start(self):
        self.process = mp.Process(
            target=capture_worker,
            args=(self.source, self.queue, self.stop_event, 2.0),
            daemon=True
        )
        self.process.start()

    def run(self):
        self.start()

        try:
            while not self.stop_event.is_set():
                try:
                    frame = self.queue.get(timeout=1)
                except Exception:
                    continue

                prediction = self.on_frame(frame)

                if self.on_prediction:
                    self.on_prediction(frame, prediction)
        except KeyboardInterrupt:
            pass
        finally:
            self.stop()

    def stop(self):
        self.stop_event.set()
        if self.process and self.process.is_alive():
            self.process.join(timeout=3)
            if self.process.is_alive():
                self.process.terminate()
                self.process.join(timeout=2)
        cv2.destroyAllWindows()