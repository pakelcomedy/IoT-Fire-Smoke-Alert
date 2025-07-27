```
IoT-Fire-Smoke-Alert/
├── CMakeLists.txt
├── sdkconfig
├── sdkconfig.defaults
├── main/
│   ├── CMakeLists.txt
│   ├── main.c             # Entry point, loop, sensor check
│   ├── wifi.c             # Wi-Fi connect
│   ├── wifi.h
│   ├── sensor.c           # MQ-2 read (ADC)
│   ├── sensor.h
│   ├── buzzer.c           # Buzzer control
│   ├── buzzer.h
│   ├── webserver.c        # Webserver (HTTP server)
│   └── webserver.h
└── web/
    ├── index.html         # UI page
    └── script.js          # Polling or SSE
```
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/b07d3345-cac8-479a-be1f-9761386bbd39" />
