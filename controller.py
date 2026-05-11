import time
import serial
from rclpy.node import Node
from robot_msgs.msg import RobotState

# --- Tuning parameters ---
KP = 0.1
KI = 0.0
KD = 0.02

KP_FWD = 1.0
TARGET_HEIGHT = 400

MAX_SPEED = 200
MIN_SPEED = 20   # Deadzone

MAX_FWD_ACCEL = 5     # PWM change per update (forward/back)
MAX_STEER_ACCEL = 10  # steering smoothing

SERIAL_PORT = "/dev/ttyUSB0"
BAUD_RATE = 115200


class PID:
    def __init__(self, kp, ki, kd):
        self.kp = kp
        self.ki = ki
        self.kd = kd
        self._integral = 0.0
        self._prev_error = 0.0

    def update(self, error, dt):
        self._integral += error * dt
        derivative = (error - self._prev_error) / dt if dt > 0 else 0.0
        self._prev_error = error
        return self.kp * error + self.ki * self._integral + self.kd * derivative

    def reset(self):
        self._integral = 0.0
        self._prev_error = 0.0


class ControllerNode(Node):
    def __init__(self, frame_width):
        super().__init__("controller")

        self._frame_width = frame_width
        self._pid = PID(KP, KI, KD)
        self._last_time = time.time()

        self._serial = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)

        # --- Smooth state ---
        self._forward_current = 0.0
        self._steering_current = 0.0

        self.create_subscription(
            RobotState,
            "robot_state",
            self._on_robot_state,
            10
        )

    def _on_robot_state(self, msg: RobotState):
        now = time.time()
        dt = now - self._last_time
        self._last_time = now

        # --- No target → stop smoothly ---
        if msg.tracked_id == -1:
            self._pid.reset()

            # ramp down instead of instant stop
            self._forward_current *= 0.8
            self._steering_current *= 0.5

            left = int(self._forward_current - self._steering_current)
            right = int(self._forward_current + self._steering_current)

            self._send(left, right)
            return

        x1, y1, x2, y2 = msg.target_bbox

        center_x = (x1 + x2) / 2.0
        bbox_height = y2 - y1

        # --- Steering (normalized) ---
        error_x = (center_x - self._frame_width / 2) / (self._frame_width / 2)

        raw_steering = self._pid.update(error_x, dt)

        # --- Steering smoothing (acceleration limit) ---
        delta_steer = raw_steering - self._steering_current
        delta_steer = max(-MAX_STEER_ACCEL, min(MAX_STEER_ACCEL, delta_steer))
        self._steering_current += delta_steer

        steering = self._steering_current

        # --- Forward control ---
        target_forward = KP_FWD * (TARGET_HEIGHT - bbox_height)

        # allow limited reverse
        target_forward = max(-60, min(MAX_SPEED, target_forward))

        # --- Forward smoothing (acceleration limit) ---
        delta_fwd = target_forward - self._forward_current
        delta_fwd = max(-MAX_FWD_ACCEL, min(MAX_FWD_ACCEL, delta_fwd))
        self._forward_current += delta_fwd

        forward = self._forward_current

        # --- Combine ---
        left = forward - steering
        right = forward + steering

        # --- Clamp ---
        left = max(-MAX_SPEED, min(MAX_SPEED, int(left)))
        right = max(-MAX_SPEED, min(MAX_SPEED, int(right)))

        # --- Deadzone ---
        if abs(left) < MIN_SPEED:
            left = 0
        if abs(right) < MIN_SPEED:
            right = 0

        # --- Send ---
        self._send(left, right)

        """self.get_logger().info(
            f"bbox=({x1:.1f},{y1:.1f},{x2:.1f},{y2:.1f}) "
            f"fwd={forward:.1f} steer={steering:.2f} L={left} R={right}"
        )"""

    def _send(self, left, right):
        cmd = f"SET {left} {right}\n"
        self._serial.write(cmd.encode())