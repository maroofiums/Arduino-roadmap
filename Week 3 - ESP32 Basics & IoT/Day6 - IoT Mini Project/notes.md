# Day6 - mart Radar Project with ESP32

**Objective:**  
Build a smart radar system using ESP32, HC-SR04 ultrasonic sensor, servo motor, and LED.  
The servo sweeps 180° to detect nearby objects. When an object is detected within a set distance, the LED turns on.

---

## Hardware Required
- ESP32 Dev Module
- HC-SR04 Ultrasonic Sensor
- Servo Motor
- LED + Resistor
- Breadboard & Jumper Wires

---

## Connections Overview

| Component | ESP32 Pin | Notes |
|-----------|-----------|-------|
| TRIG      | GPIO 5    | Optional 1kΩ resistor in series |
| ECHO      | GPIO 18   | Use voltage divider to bring 5V echo to 3.3V safe level |
| SERVO     | GPIO 4    | Power from 5V, signal to GPIO4 |
| LED       | GPIO 2    | Use 220Ω resistor in series |
| GND       | Common    | All components share common ground |

**Tip:** Label wires on your breadboard for clarity when taking photos.

---

## Code Overview

The code (in separate file) does the following:

1. Initializes ESP32 pins and serial monitor.
2. Sweeps the servo from 0° to 180°.
3. Measures distance using the HC-SR04 ultrasonic sensor.
4. Turns on the LED when an object is detected within a threshold distance.
5. Prints angle and distance data to Serial Monitor for real-time monitoring.

**Concepts Used:**
- PWM control for servo
- Digital input/output for LED and sensor
- Timing functions for distance measurement
- Conditional logic for threshold detection

---