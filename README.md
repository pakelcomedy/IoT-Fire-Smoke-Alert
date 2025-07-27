```
IoT-Fire-Smoke-Alert/
├── Cargo.toml
├── memory.x
├── .cargo/
│   └── config.toml
├── src/
│   ├── main.rs         # Setup Wi-Fi, loop, sensor read, handle alert
│   ├── wifi.rs         # Connect to Wi-Fi
│   ├── sensor.rs       # Baca data dari MQ-2 atau flame sensor
│   ├── buzzer.rs       # Kontrol buzzer aktif saat deteksi
│   └── http.rs         # Web server & notifikasi real-time (e.g. SSE/REST)
└── website/            # UI notifikasi web (optional)
    ├── index.html
    └── script.js
```
