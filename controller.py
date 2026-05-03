
import time

import serial
from rclpy.node import Node
from robot_msgs.msg import RobotState


class ControllerNode(Node):
    def __init__(self, frame_width):
        super().__init__("controller")
        self.frame_width = float(frame_width) if frame_width else 1.0

        # --- Serial settings ---
        self.serial_port = "/dev/ttyUSB0"
        self.serial_baud = 115200
        self.serial_retry_s = 1.0

        # --- Control loop settings ---
        self.command_hz = 10.0
        self.command_period_s = 1.0 / self.command_hz
        self.track_timeout_s = 0.25

        # --- Steering / speed tuning ---
        self.center_deadband = 0.05
        self.target_width_ratio = 0.30
        self.width_deadband = 0.015

        self.k_turn = 220.0
        self.k_forward = 900.0

        self.max_turn_pwm = 90.0
        self.max_forward_pwm = 120.0
        self.max_reverse_pwm = 100.0
        self.allow_reverse = True
        self.min_move_pwm = 55.0
        self.slew_per_step = 20.0

        self.debug_enabled = True
        self.debug_interval_s = 0.5

        self.serial_conn = None
        self.last_serial_attempt = 0.0
        self.last_debug_time = 0.0

        self.has_target = False
        self.last_track_time = 0.0
        self.latest_bbox = [0.0, 0.0, 0.0, 0.0]

        self.cmd_left = 0.0
        self.cmd_right = 0.0

        self.subscription = self.create_subscription(
            RobotState,
            "robot_state",
            self.callback,
            10,
        )

        self.timer = self.create_timer(self.command_period_s, self.control_loop)
        self._connect_serial()

    def callback(self, msg):
        if msg.tracked_id == -1:
            self.has_target = False
            return

        self.has_target = True
        self.last_track_time = time.monotonic()
        self.latest_bbox = [float(v) for v in msg.target_bbox]

    def control_loop(self):
        now = time.monotonic()

        if (not self.has_target) or (now - self.last_track_time > self.track_timeout_s):
            self._apply_command(0.0, 0.0)
            self._send_stop()
            return

        target_left, target_right, debug_info = self._compute_motor_commands(self.latest_bbox)
        self._apply_command(target_left, target_right)
        self._send_set(int(round(self.cmd_left)), int(round(self.cmd_right)))

        if self.debug_enabled and (now - self.last_debug_time >= self.debug_interval_s):
            self.last_debug_time = now
            self.get_logger().info(
                "x_err={:.3f} width={:.3f} fwd={:.1f} turn={:.1f} L={} R={}".format(
                    debug_info["x_error"],
                    debug_info["width_ratio"],
                    debug_info["forward"],
                    debug_info["turn"],
                    int(round(self.cmd_left)),
                    int(round(self.cmd_right)),
                )
            )

    def _compute_motor_commands(self, bbox):
        x1, y1, x2, y2 = bbox

        center_x = (x1 + x2) / 2.0
        half_width = self.frame_width / 2.0
        x_error = (center_x - half_width) / half_width
        x_error = max(-1.0, min(1.0, x_error))
        if abs(x_error) < self.center_deadband:
            x_error = 0.0

        width_ratio = max(0.0, (x2 - x1) / self.frame_width)
        width_error = self.target_width_ratio - width_ratio
        if abs(width_error) < self.width_deadband:
            width_error = 0.0

        turn_ratio = self.k_turn * x_error / 255.0
        turn_ratio = max(-1.0, min(1.0, turn_ratio))

        forward = self.k_forward * width_error
        if not self.allow_reverse:
            forward = max(0.0, forward)
        forward = max(-self.max_reverse_pwm, min(self.max_forward_pwm, forward))

        if 0.0 < abs(forward) < self.min_move_pwm:
            forward = self.min_move_pwm if forward > 0.0 else -self.min_move_pwm

        # Blend mix: both motors always run in the same direction,
        # turn_ratio scales how much one side yields to the other.
        # Positive x_error = person to the right → robot turns right → left motor yields.
        if turn_ratio >= 0.0:
            left = forward * (1.0 - turn_ratio)
            right = forward
        else:
            left = forward
            right = forward * (1.0 + turn_ratio)

        turn = turn_ratio * 255.0  # for debug only

        left = max(-255.0, min(255.0, left))
        right = max(-255.0, min(255.0, right))

        debug_info = {
            "x_error": x_error,
            "width_ratio": width_ratio,
            "forward": forward,
            "turn": turn,
        }

        return left, right, debug_info

    def _apply_command(self, target_left, target_right):
        self.cmd_left += max(-self.slew_per_step, min(self.slew_per_step, target_left - self.cmd_left))
        self.cmd_right += max(-self.slew_per_step, min(self.slew_per_step, target_right - self.cmd_right))

    def _connect_serial(self):
        try:
            self.serial_conn = serial.Serial(self.serial_port, self.serial_baud, timeout=0.05)
            self.get_logger().info(f"Connected Arduino on {self.serial_port} @ {self.serial_baud}")
        except serial.SerialException as exc:
            self.serial_conn = None
            self.get_logger().warn(f"Could not open serial {self.serial_port}: {exc}")

    def _ensure_serial(self):
        if self.serial_conn is not None and self.serial_conn.is_open:
            return True

        now = time.monotonic()
        if now - self.last_serial_attempt < self.serial_retry_s:
            return False

        self.last_serial_attempt = now
        self._connect_serial()
        return self.serial_conn is not None and self.serial_conn.is_open

    def _send_line(self, line):
        if not self._ensure_serial():
            return

        try:
            self.serial_conn.write((line + "\n").encode("utf-8"))
        except serial.SerialException as exc:
            self.get_logger().warn(f"Serial write failed: {exc}")
            try:
                self.serial_conn.close()
            except Exception:
                pass
            self.serial_conn = None

    def _send_set(self, left_pwm, right_pwm):
        self._send_line(f"SET {left_pwm} {right_pwm}")

    def _send_stop(self):
        self.cmd_left = 0.0
        self.cmd_right = 0.0
        self._send_line("STOP")

    def destroy_node(self):
        self._send_stop()

        if self.serial_conn is not None:
            try:
                self.serial_conn.close()
            except Exception:
                pass

        return super().destroy_node()