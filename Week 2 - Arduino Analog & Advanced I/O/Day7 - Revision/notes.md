# 🗓️ Week 2 — Day 7

## **Revision: Sensor → Input → Output**

Goal: **Har sensor aur component ka clear mapping** yaad karna, taake future projects me easy ho.

---

## 🔹 Summary Table (Week 1 + Week 2)

| Sensor / Component        | Input / Action                | Output / Actuator / Reaction | Notes / Logic                                                                                 |
| ------------------------- | ----------------------------- | ---------------------------- | --------------------------------------------------------------------------------------------- |
| **LED**                   | `digitalWrite(HIGH/LOW)`      | ON / OFF                     | Basic output, used with button or sensor                                                      |
| **Button**                | Press (LOW with INPUT_PULLUP) | Detect press                 | Input, triggers LED / Servo / action                                                          |
| **Servo Motor**           | Angle command (0–180)         | Rotates to angle             | PWM signal, use Servo.h                                                                       |
| **DHT11**                 | Temperature & Humidity        | LED / Serial Monitor alert   | `readTemperature()`, `readHumidity()`, threshold logic                                        |
| **HC-SR04**               | Ultrasonic distance           | LED / Servo / Serial Alert   | TRIG → send pulse, ECHO → read pulseIn(), distance formula: `distance = duration * 0.034 / 2` |
| **Potentiometer**         | Analog value (0–1023)         | LED brightness / PWM output  | `analogRead()`, map to 0–255 for LED brightness                                               |
| **LED Sequence**          | Loop timing                   | Multiple LEDs blink sequence | Traffic-light style, practice loops                                                           |
| **Combined Mini Project** | Sensor + Button               | LED + Servo + Serial Alert   | Integration of input, logic, output                                                           |

---

## 🔹 Key Patterns Learned

1. **Input → Logic → Output**

   * Button → LED
   * Sensor → Conditional → Action
   * Core IoT / Automation pattern

2. **Timing & Delays**

   * `delay()` for visible effects
   * `delayMicroseconds()` for sensors like HC-SR04

3. **Conditional Logic**

   * Thresholds (temp > 30°C, distance < 15 cm)
   * Event-driven automation

4. **Libraries**

   * `Servo.h` → Servo control
   * `DHT.h` → Temperature/Humidity sensor

5. **Serial Monitor Debugging**

   * Always print values first → helps in troubleshooting

---

## 🧠 Mentor Advice / Notes

* **Breadboard & wiring**: Pehle har component alag test karo → combine later
* **Thresholds**: Adjustable rakhna, real world me environment different hota hai
* **Code readability**: `#define` pins, comment lines → debugging easier
* **Memory check**: UNO limited memory → big projects me optimize karo

---