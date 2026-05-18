import json
from http import HTTPStatus
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from threading import Thread
from urllib.parse import parse_qs, urlparse

from runtime_config import RuntimeTuningStore


HTML_PAGE = """<!DOCTYPE html>
<html lang="sv">
<head>
  <meta charset="utf-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <title>Robot tuning</title>
  <style>
    :root {
      color-scheme: dark;
      --bg: #0b1020;
      --panel: rgba(16, 24, 45, 0.92);
      --panel-border: rgba(117, 138, 255, 0.24);
      --text: #f3f6ff;
      --muted: #a8b2d6;
      --accent: #6ee7ff;
      --accent-2: #7cfc9a;
      --danger: #ff7a90;
      --shadow: 0 20px 60px rgba(0, 0, 0, 0.35);
    }

    * { box-sizing: border-box; }
    body {
      margin: 0;
      min-height: 100vh;
      font-family: Inter, ui-sans-serif, system-ui, -apple-system, BlinkMacSystemFont, sans-serif;
      background:
        radial-gradient(circle at top left, rgba(110, 231, 255, 0.18), transparent 30%),
        radial-gradient(circle at bottom right, rgba(124, 252, 154, 0.12), transparent 28%),
        linear-gradient(160deg, #070b17 0%, #101a33 55%, #0b1020 100%);
      color: var(--text);
      display: grid;
      place-items: center;
      padding: 18px;
    }

    .shell {
      width: min(100%, 720px);
      background: var(--panel);
      border: 1px solid var(--panel-border);
      border-radius: 24px;
      box-shadow: var(--shadow);
      overflow: hidden;
      backdrop-filter: blur(12px);
    }

    header {
      padding: 22px 22px 12px;
      border-bottom: 1px solid rgba(255, 255, 255, 0.08);
    }

    h1 {
      margin: 0;
      font-size: clamp(1.5rem, 3vw, 2.25rem);
      letter-spacing: -0.03em;
    }

    p {
      margin: 8px 0 0;
      color: var(--muted);
      line-height: 1.5;
    }

    main {
      padding: 18px 22px 24px;
      display: grid;
      gap: 16px;
    }

    .grid {
      display: grid;
      grid-template-columns: repeat(2, minmax(0, 1fr));
      gap: 12px;
    }

    .card {
      background: rgba(255, 255, 255, 0.03);
      border: 1px solid rgba(255, 255, 255, 0.08);
      border-radius: 18px;
      padding: 14px;
    }

    label {
      display: grid;
      gap: 8px;
      font-size: 0.92rem;
      color: var(--muted);
    }

    input {
      width: 100%;
      border: 1px solid rgba(255, 255, 255, 0.14);
      border-radius: 14px;
      padding: 14px 14px;
      font: inherit;
      color: var(--text);
      background: rgba(8, 12, 26, 0.9);
      outline: none;
    }

    input:focus {
      border-color: rgba(110, 231, 255, 0.7);
      box-shadow: 0 0 0 4px rgba(110, 231, 255, 0.12);
    }

    .full {
      grid-column: 1 / -1;
    }

    .actions {
      display: flex;
      gap: 12px;
      flex-wrap: wrap;
      align-items: center;
    }

    button {
      border: 0;
      border-radius: 999px;
      padding: 14px 18px;
      font: inherit;
      font-weight: 700;
      color: #071018;
      background: linear-gradient(135deg, var(--accent), var(--accent-2));
      cursor: pointer;
      min-width: 140px;
    }

    .secondary {
      background: rgba(255, 255, 255, 0.08);
      color: var(--text);
      border: 1px solid rgba(255, 255, 255, 0.1);
    }

    .status {
      min-height: 1.5em;
      color: var(--muted);
      font-size: 0.95rem;
    }

    .status.error { color: var(--danger); }

    .value-row {
      display: flex;
      justify-content: space-between;
      gap: 12px;
      font-size: 0.95rem;
      color: var(--text);
    }

    .value-row span {
      color: var(--muted);
    }

    @media (max-width: 640px) {
      .grid { grid-template-columns: 1fr; }
      header, main { padding-left: 16px; padding-right: 16px; }
      button { width: 100%; }
    }
  </style>
</head>
<body>
  <section class="shell">
    <header>
      <h1>Robot tuning</h1>
      <p>Justera PID och forward speed direkt från mobilen medan roboten kör.</p>
    </header>
    <main>
      <div class="card">
        <div class="value-row"><strong>KP</strong><span id="kp-value">-</span></div>
        <div class="value-row"><strong>KI</strong><span id="ki-value">-</span></div>
        <div class="value-row"><strong>KD</strong><span id="kd-value">-</span></div>
        <div class="value-row"><strong>Forward speed %</strong><span id="speed-value">-</span></div>
      </div>

      <form id="tuning-form" class="grid">
        <label>
          KP
          <input id="kp" name="kp" type="number" step="0.1" min="0" inputmode="decimal" required />
        </label>
        <label>
          KI
          <input id="ki" name="ki" type="number" step="0.01" min="0" inputmode="decimal" required />
        </label>
        <label>
          KD
          <input id="kd" name="kd" type="number" step="0.01" min="0" inputmode="decimal" required />
        </label>
        <label>
          Forward speed percent
          <input id="forward_speed_percent" name="forward_speed_percent" type="range" min="0" max="100" step="1" />
        </label>
        <div class="actions full">
          <button type="submit">Spara</button>
          <button type="button" id="refresh" class="secondary">Läs om</button>
        </div>
        <div id="status" class="status full"></div>
      </form>
    </main>
  </section>

  <script>
    const statusEl = document.getElementById('status');
    const form = document.getElementById('tuning-form');

    const fields = {
      kp: document.getElementById('kp'),
      ki: document.getElementById('ki'),
      kd: document.getElementById('kd'),
      forward_speed_percent: document.getElementById('forward_speed_percent'),
    };

    const valueLabels = {
      kp: document.getElementById('kp-value'),
      ki: document.getElementById('ki-value'),
      kd: document.getElementById('kd-value'),
      forward_speed_percent: document.getElementById('speed-value'),
    };

    function setStatus(text, isError = false) {
      statusEl.textContent = text;
      statusEl.classList.toggle('error', isError);
    }

    function renderValues(data) {
      fields.kp.value = data.kp;
      fields.ki.value = data.ki;
      fields.kd.value = data.kd;
      fields.forward_speed_percent.value = data.forward_speed_percent;

      valueLabels.kp.textContent = Number(data.kp).toFixed(2);
      valueLabels.ki.textContent = Number(data.ki).toFixed(2);
      valueLabels.kd.textContent = Number(data.kd).toFixed(2);
      valueLabels.forward_speed_percent.textContent = `${Number(data.forward_speed_percent).toFixed(0)}%`;
    }

    async function loadValues() {
      const response = await fetch('/api/tuning');
      if (!response.ok) {
        throw new Error(`HTTP ${response.status}`);
      }

      const data = await response.json();
      renderValues(data);
      setStatus('Aktuella värden uppdaterade.');
    }

    fields.forward_speed_percent.addEventListener('input', () => {
      valueLabels.forward_speed_percent.textContent = `${Number(fields.forward_speed_percent.value).toFixed(0)}%`;
    });

    form.addEventListener('submit', async (event) => {
      event.preventDefault();
      setStatus('Sparar...');

      const payload = {
        kp: fields.kp.value,
        ki: fields.ki.value,
        kd: fields.kd.value,
        forward_speed_percent: fields.forward_speed_percent.value,
      };

      const response = await fetch('/api/tuning', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify(payload),
      });

      const data = await response.json();
      if (!response.ok) {
        setStatus(data.error || 'Kunde inte spara värdena.', true);
        return;
      }

      renderValues(data);
      setStatus('Värden uppdaterade direkt i runtime.');
    });

    document.getElementById('refresh').addEventListener('click', async () => {
      try {
        await loadValues();
      } catch (error) {
        setStatus(`Kunde inte läsa värden: ${error.message}`, true);
      }
    });

    loadValues().catch((error) => {
      setStatus(`Kunde inte hämta initiala värden: ${error.message}`, true);
    });
  </script>
</body>
</html>
"""


class TuningHTTPServer(ThreadingHTTPServer):
    def __init__(self, server_address, request_handler_class, tuning_store: RuntimeTuningStore):
        super().__init__(server_address, request_handler_class)
        self.tuning_store = tuning_store


class TuningRequestHandler(BaseHTTPRequestHandler):
    server_version = "RobotTuningHTTP/1.0"

    def do_GET(self):
        path = urlparse(self.path).path

        if path in {"/", "/index.html"}:
            self._send_html(HTML_PAGE)
            return

        if path == "/api/tuning":
            tuning, version = self.server.tuning_store.snapshot()
            self._send_json({**tuning.as_dict(), "version": version})
            return

        self.send_error(HTTPStatus.NOT_FOUND, "Not found")

    def do_POST(self):
        path = urlparse(self.path).path
        if path != "/api/tuning":
            self.send_error(HTTPStatus.NOT_FOUND, "Not found")
            return

        try:
            payload = self._read_payload()
            tuning, version = self.server.tuning_store.update(**payload)
        except ValueError as exc:
            self._send_json({"error": str(exc)}, status=HTTPStatus.BAD_REQUEST)
            return
        except json.JSONDecodeError:
            self._send_json({"error": "Invalid JSON payload"}, status=HTTPStatus.BAD_REQUEST)
            return

        self._send_json({**tuning.as_dict(), "version": version})

    def _read_payload(self):
        content_length = int(self.headers.get("Content-Length", "0"))
        raw_body = self.rfile.read(content_length).decode("utf-8") if content_length else ""
        content_type = self.headers.get_content_type()

        if content_type == "application/json":
            data = json.loads(raw_body or "{}")
            return {
                "kp": data.get("kp"),
                "ki": data.get("ki"),
                "kd": data.get("kd"),
                "forward_speed_percent": data.get("forward_speed_percent"),
            }

        parsed = parse_qs(raw_body, keep_blank_values=True)
        return {
            "kp": parsed.get("kp", [None])[0],
            "ki": parsed.get("ki", [None])[0],
            "kd": parsed.get("kd", [None])[0],
            "forward_speed_percent": parsed.get("forward_speed_percent", [None])[0],
        }

    def _send_html(self, body):
        encoded = body.encode("utf-8")
        self.send_response(HTTPStatus.OK)
        self.send_header("Content-Type", "text/html; charset=utf-8")
        self.send_header("Content-Length", str(len(encoded)))
        self.end_headers()
        self.wfile.write(encoded)

    def _send_json(self, payload, status=HTTPStatus.OK):
        encoded = json.dumps(payload).encode("utf-8")
        self.send_response(status)
        self.send_header("Content-Type", "application/json; charset=utf-8")
        self.send_header("Content-Length", str(len(encoded)))
        self.end_headers()
        self.wfile.write(encoded)

    def log_message(self, format, *args):
        self.server.logger.info("%s - %s", self.address_string(), format % args)


class TuningWebApp:
    def __init__(self, host: str, port: int, tuning_store: RuntimeTuningStore):
        self.host = host
        self.port = port
        self.tuning_store = tuning_store
        self.logger = None
        self.server = TuningHTTPServer((host, port), TuningRequestHandler, tuning_store)
        self.server.logger = self
        self._thread = Thread(target=self.server.serve_forever, name="tuning-web", daemon=True)

    def info(self, message, *args):
        if args:
            message = message % args
        print(message)

    def start(self):
        self._thread.start()
        bound_host, bound_port = self.server.server_address
        print(f"Runtime tuning UI listening on http://{bound_host}:{bound_port}")

    def stop(self):
        self.server.shutdown()
        self.server.server_close()
        if self._thread.is_alive():
            self._thread.join(timeout=2.0)