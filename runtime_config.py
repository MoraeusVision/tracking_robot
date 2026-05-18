from dataclasses import dataclass, asdict
from math import isfinite
from threading import Lock


@dataclass(frozen=True)
class RuntimeTuning:
    kp: float = 18.0
    ki: float = 0.0
    kd: float = 0.0
    forward_speed_percent: float = 50.0

    def as_dict(self):
        return asdict(self)


class RuntimeTuningStore:
    def __init__(self, initial: RuntimeTuning | None = None):
        self._lock = Lock()
        self._state = initial if initial is not None else RuntimeTuning()
        self._version = 0

    def snapshot(self) -> tuple[RuntimeTuning, int]:
        with self._lock:
            return self._state, self._version

    def update(self, *, kp=None, ki=None, kd=None, forward_speed_percent=None):
        with self._lock:
            next_state = RuntimeTuning(
                kp=self._coerce_gain("kp", kp, self._state.kp),
                ki=self._coerce_gain("ki", ki, self._state.ki),
                kd=self._coerce_gain("kd", kd, self._state.kd),
                forward_speed_percent=self._coerce_speed(
                    forward_speed_percent,
                    self._state.forward_speed_percent,
                ),
            )

            if next_state != self._state:
                self._state = next_state
                self._version += 1

            return self._state, self._version

    @staticmethod
    def _coerce_gain(name, value, current):
        if value is None or value == "":
            return current

        number = float(value)
        if not isfinite(number):
            raise ValueError(f"{name} must be a finite number")
        if number < 0:
            raise ValueError(f"{name} must be greater than or equal to 0")

        return number

    @staticmethod
    def _coerce_speed(value, current):
        if value is None or value == "":
            return current

        number = float(value)
        if not isfinite(number):
            raise ValueError("forward_speed_percent must be a finite number")
        if number < 0 or number > 100:
            raise ValueError("forward_speed_percent must be between 0 and 100")

        return number