# iot-flood-detection-dam-controller
IoT-based flood detection and dam controller system using ESP32, ultrasonic sensors, and a moisture sensor to monitor water levels, trigger alerts, and control a DC pump.

# IoT-Based Flood Detection and Dam Controller System

## 📌 Project Overview

The IoT-Based Flood Detection and Dam Controller System is an embedded systems project designed to monitor water levels and detect potential flood conditions using sensors and an ESP32 microcontroller. The system displays water-level information, generates alerts, and controls a DC pump based on predefined water-level thresholds.

## 🎯 Objectives

- Monitor water levels using ultrasonic sensors.
- Detect rain or moisture using a moisture sensor.
- Display water-level status on a 16×2 I2C LCD.
- Generate alerts using a buzzer when critical water levels are detected.
- Control a DC pump based on programmed conditions.
- Support IoT monitoring through ESP32 Wi-Fi connectivity.

## 🛠️ Hardware Components

- ESP32 Microcontroller
- Ultrasonic Sensors (HC-SR04) × 2
- Moisture Sensor
- 16×2 I2C LCD Display
- Two-Channel Relay Module
- Buzzer
- DC Pump
- DC Battery
- PCB and Jumper Wires

## 💻 Software and Technologies

- Arduino IDE
- Embedded C/C++ (Arduino framework)
- ESP32 Wi-Fi
- I2C Communication
- MIT App Inventor

## ⚙️ Working Principle

1. The ultrasonic sensors measure the distance corresponding to the water level.
2. The ESP32 processes sensor readings and evaluates predefined thresholds.
3. The LCD displays the current water-level status.
4. When a critical level is detected, the system activates the buzzer and controls the pump output.
5. Wi-Fi connectivity supports remote monitoring functionality.

## 📊 Key Features

- Water-level monitoring
- Rain or moisture detection
- LCD status display
- Buzzer-based alerts
- Automatic pump control
- Wi-Fi-enabled IoT functionality

## 📂 Project Structure

```text
iot-flood-detection-dam-controller/
├── README.md
├── docs/
│   └── IoT_Flood_Detection_Project_Report.pdf
├── src/
│   └── flood_detection.ino
└── images/
    ├── block_diagram.png
    └── circuit_diagram.png
```


## 🧪 Applications

- Academic IoT and embedded systems demonstrations
- Water-level monitoring prototypes
- Flood-warning system demonstrations
- Automated pump-control applications

## ⚠️ Limitations

The system depends on sensor accuracy, power availability, and network connectivity. It is an academic prototype and is not intended to replace certified flood-warning infrastructure or professional dam-control systems.

## 🔮 Future Scope

- Integration with weather forecast data
- Improved flood-risk prediction
- Cloud-based data logging and visualization
- Remote notifications and monitoring
- Enhanced sensor reliability and fail-safe mechanisms

## 👩‍💻 Project Team

- Mahek Tajuddin Sayyad
- Sneha Ramesh Kshirsagar
- Pratiksha Siddharth Vakale

🎥 Project Demonstration

Watch the demonstration video of the IoT-Based Flood Detection and Dam Controller System.


---

*This repository documents an academic project on IoT-based flood detection and dam control.*
