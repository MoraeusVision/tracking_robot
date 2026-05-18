# tracking_robot
A robot following the person who gives it command through hands

## Minimal autostart on Jetson (single container)

This setup uses one container (no docker compose) and a systemd service.
If the app crashes, Docker keeps retrying because the container is started with `--restart always`.

### 1. Build image

```bash
cd /workspace
docker build -t tracking-robot:jetson .
```

### 2. Install systemd service

```bash
sudo cp /workspace/deploy/tracking-robot.service /etc/systemd/system/tracking-robot.service
sudo systemctl daemon-reload
sudo systemctl enable tracking-robot.service
sudo systemctl start tracking-robot.service
```

### 3. Check status and logs

```bash
sudo systemctl status tracking-robot.service
docker ps --filter name=tracking-robot
docker logs -f tracking-robot
```

### Notes

- The service currently maps camera `/dev/video0` and serial `/dev/ttyUSB0`.
- If your serial device changes after reboot, update `--device` to a stable path under `/dev/serial/by-id/`.
- Runtime tuning is available on the local network at `http://<robot-ip>:8000` when the app is running.
- Use the page to update `KP`, `KI`, `KD`, and forward speed percent live without restarting the process.
