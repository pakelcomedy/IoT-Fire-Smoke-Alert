# 🔥 IoT Fire & Smoke Alert System (ESP32 + MQ-2)

A simple yet powerful real-time fire and smoke detection system using an ESP32 and MQ-2 sensor. Alerts are triggered via buzzer and served through a web-based dashboard over Wi-Fi.

---

## 📦 Project Structure

```
IoT-Fire-Smoke-Alert/
├── CMakeLists.txt
├── sdkconfig
├── sdkconfig.defaults
├── main/
│   ├── main.c             # Entry point, loop, sensor check
│   ├── wifi.c / wifi.h    # Wi-Fi connection
│   ├── sensor.c / sensor.h# MQ-2 analog read
│   ├── buzzer.c / buzzer.h# Buzzer control
│   └── webserver.c / .h   # HTTP webserver
└── web/
    ├── index.html         # Simple UI
    └── script.js          # Auto-refresh or SSE (optional)
```

---

## 🚀 Features

* 🔥 Detects fire and smoke using MQ-2 sensor
* 📢 Activates buzzer on threshold exceed
* 🌐 Hosts a real-time web interface (served by ESP32)
* 📶 Wi-Fi configuration for easy monitoring
* ⚡ Fast and lightweight (no external dependencies)

---

## 🛠️ How It Works

1. **Sensor Monitoring:**
   MQ-2 reads analog values from smoke/gas/fire in the air (via ADC).

2. **Threshold Check:**
   In `main.c`, the system loops and checks sensor values. If it exceeds a defined threshold, the buzzer is triggered and the web UI reflects the alert.

3. **Web Dashboard:**
   A minimal web server runs on the ESP32. HTML/JS is served to browser clients. The client polls data every few seconds (or via Server-Sent Events) to show real-time status.

4. **Wi-Fi Connection:**
   Connects automatically to the predefined SSID and password (configured in `wifi.c`).

---

## 🌐 Live Web Interface

Once connected to Wi-Fi, open your browser and go to:

```
http://<ESP32-IP>/
```

You’ll see:

* ✅ Current sensor value
* ⚠️  Fire/smoke alerts
* 📈 Auto-refresh chart or status

---

## 🔧 Setup & Build

### Requirements

* ESP32 board
* ESP-IDF (v5.x recommended)
* MQ-2 sensor (analog)
* Buzzer (optional)
* VS Code + ESP-IDF plugin (optional)

### Steps

```bash
git clone https://github.com/pakelcomedy/IoT-Fire-Smoke-Alert.git
cd IoT-Fire-Smoke-Alert
idf.py set-target esp32
idf.py menuconfig   # set Wi-Fi SSID/PASSWORD and thresholds
idf.py build
idf.py flash monitor
```

---

## 📸 Screenshot

![Web UI Screenshot](https://github.com/user-attachments/assets/b07d3345-cac8-479a-be1f-9761386bbd39)

---

## ⚠️ Note

* Sensor values may vary; calibrate threshold based on your room/environment.
* For serious applications (e.g. real fires), **use certified fire detectors**.

---

## 📃 License

MIT License — Free to use and modify.
