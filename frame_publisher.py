import cv2
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge


class FramePublisher(Node):
    def __init__(self):
        super().__init__("frame_publisher")
        self.publisher_ = self.create_publisher(Image, "image_raw", 10)
        self.timer = self.create_timer(0.01, self.time_callback)
        self.bridge = CvBridge()
        self.cap = cv2.VideoCapture(0)
        self.frame_counter = 0

    def time_callback(self):
        ret, frame = self.cap.read()
        if ret:
            image = self.bridge.cv2_to_imgmsg(frame, "bgr8")
            self.publisher_.publish(image)

            