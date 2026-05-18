import time
import serial
from rclpy.node import Node
from robot_msgs.msg import RobotState
from runtime_config import RuntimeTuningStore

MAX_SPEED = 200
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

    def set_gains(self, kp, ki, kd):
        self.kp = kp
        self.ki = ki
        self.kd = kd


class ControllerNode(Node):
    def __init__(self, frame_width, tuning_store: RuntimeTuningStore):
        super().__init__("controller")

        self._frame_width = frame_width
        self._tuning_store = tuning_store
        tuning, version = self._tuning_store.snapshot()
        self._pid = PID(tuning.kp, tuning.ki, tuning.kd)
        self._forward_speed_percent = tuning.forward_speed_percent
        self._applied_version = version
        self._last_time = time.time()

        self._serial = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)

        self.create_subscription(
            RobotState,
            "robot_state",
            self._on_robot_state,
            10
        )

        self.publisher = self.create_publisher(
            RobotState,
            "robot_state",
            10,
        )

        self._log_tuning(tuning)

    def _log_tuning(self, tuning):
        self.get_logger().info(
            f"KP={tuning.kp}, KI={tuning.ki}, KD={tuning.kd}\n"
            f"Forward speed: {tuning.forward_speed_percent}% of {MAX_SPEED}"
        )

    def _apply_tuning(self):
        tuning, version = self._tuning_store.snapshot()
        if version == self._applied_version:
            return

        gains_changed = (
            tuning.kp != self._pid.kp
            or tuning.ki != self._pid.ki
            or tuning.kd != self._pid.kd
        )

        if gains_changed:
            self._pid.set_gains(tuning.kp, tuning.ki, tuning.kd)
            self._pid.reset()
            self._log_tuning(tuning)

        self._forward_speed_percent = tuning.forward_speed_percent
        self._applied_version = version

    def _on_robot_state(self, msg: RobotState):
        now = time.time()
        dt = now - self._last_time
        self._last_time = now

        self._apply_tuning()

        # No target → stop
        if msg.tracked_id == -1:
            self._pid.reset()
            self._send(0, 0)
            return

        x1, y1, x2, y2 = msg.target_bbox
        center_x = (x1 + x2) / 2.0

        # Steering (normalized error)
        error_x = (center_x - self._frame_width / 2) / (self._frame_width / 2)
        print(f"Error_x: {error_x}")
        steering = self._pid.update(error_x, dt)
        print(f"Steering: {steering}")

        # Forward speed (constant, as percent of MAX_SPEED)
        forward = (self._forward_speed_percent / 100.0) * MAX_SPEED

        # Combine
        left = forward - steering
        right = forward + steering

        # Clamp
        left = max(-MAX_SPEED, min(MAX_SPEED, int(left)))
        right = max(-MAX_SPEED, min(MAX_SPEED, int(right)))

        self._send(left, right)

    def _send(self, left, right):
        cmd = f"SET {left} {right}\n"
        print(cmd)
        self._serial.write(cmd.encode())