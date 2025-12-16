# Arduino Roadmap
---

## **Week 1 — Arduino Basics & Digital I/O**

**Goal:** Understand microcontroller, pins, input/output, and basic sensors.

| Day | Topic                     | Hands-on Exercise                                       | Concepts/Notes                                                 |
| --- | ------------------------- | ------------------------------------------------------- | -------------------------------------------------------------- |
| 1   | Arduino IDE & Blink       | Blink onboard LED, change blink speed, add external LED | `pinMode`, `digitalWrite`, `delay`, sketch workflow            |
| 2   | Digital Input (Button)    | Connect button → LED ON/OFF                             | `digitalRead`, pull-up/pull-down resistors, input debouncing   |
| 3   | Servo Motor Basics        | Move servo 0° → 90° → 180° → back                       | PWM, `Servo.h` library, angles, control logic                  |
| 4   | DHT11 Sensor              | Read temperature & humidity, print on Serial Monitor    | Analog vs digital sensors, sensor libraries, serial debugging  |
| 5   | HC-SR04 Ultrasonic Sensor | Measure distance → print in cm                          | `pulseIn()`, timing calculation, obstacle detection            |
| 6   | Mini Project              | Button → LED → Servo sequence                           | Combine input + output logic, flowchart style notes            |
| 7   | Revision & Notes          | Draw circuit diagrams of all components used            | Write “Input → Logic → Output” flow for each, reinforce memory |

---

## **Week 2 — Arduino Analog & Advanced I/O**

**Goal:** Mix digital + analog, learn lights and more interactive controls.

| Day | Topic                 | Hands-on Exercise                                          | Concepts/Notes                          |
| --- | --------------------- | ---------------------------------------------------------- | --------------------------------------- |
| 1   | Analog Input          | Connect potentiometer → control LED brightness             | `analogRead()`, PWM, map values         |
| 2   | Multiple LEDs         | Blink patterns, sequence LEDs like traffic lights          | Loops, timing, sequencing               |
| 3   | Button + Servo        | Press button → Servo moves + LED blinks                    | Combine input + output with timing      |
| 4   | Sensor + Output Logic | DHT11 → if temp > 30°C → LED ON                            | Conditional logic, threshold triggering |
| 5   | HC-SR04 + Servo       | Object detected → Servo moves                              | Event-driven logic, function usage      |
| 6   | Mini Project          | Simple alarm: object detected → LED + Servo + Serial alert | Integrate multiple components           |
| 7   | Revision              | Make a summary table: Sensor → Input → Output              | Helpful for bigger IoT projects         |

---

## **Week 3 — ESP32 Basics & IoT**

**Goal:** Learn WiFi, ESP32 pins, online communication.

| Day | Topic              | Hands-on Exercise                                     | Concepts/Notes                                        |
| --- | ------------------ | ----------------------------------------------------- | ----------------------------------------------------- |
| 1   | ESP32 Blink & Pins | Blink onboard LED, identify GPIO pins                 | ESP32 vs Arduino UNO differences                      |
| 2   | WiFi Connection    | Connect ESP32 to WiFi, print IP                       | `WiFi.h` library, Serial Monitor debugging            |
| 3   | HTTP GET Request   | Send dummy GET request to API                         | `HTTPClient` library, JSON basics                     |
| 4   | DHT11 → Cloud      | Send temperature & humidity to **ThingSpeak**         | API keys, HTTP POST, data logging                     |
| 5   | Remote Control     | Control LED/Servo via ESP32 web server                | HTML basics, server endpoints, GPIO control           |
| 6   | IoT Mini Project   | Web-controlled LED + sensor readings displayed online | End-to-end IoT workflow                               |
| 7   | Revision & Notes   | Draw ESP32 + WiFi + Sensors diagram                   | Data flow understanding, connections, online → device |

---

## **Week 4 — Advanced IoT & Mini Projects**

**Goal:** Integrate multiple sensors + actuators + online control.

| Day | Topic                   | Hands-on Exercise                                   | Concepts/Notes                                      |
| --- | ----------------------- | --------------------------------------------------- | --------------------------------------------------- |
| 1   | Multiple Sensors        | DHT11 + HC-SR04 → Display on Serial                 | Multi-sensor reading, timing                        |
| 2   | Threshold Alerts        | Temp > 30°C → LED + Buzzer (if available)           | Conditional logic, event handling                   |
| 3   | ESP32 Web Server        | Display sensor values on simple webpage             | HTML table, page refresh, dynamic updates           |
| 4   | Remote Control + Sensor | Control servo/LED via webpage                       | Combine input & output over WiFi                    |
| 5   | MQTT Introduction       | Send sensor data to MQTT broker                     | Publisher & Subscriber concept, IoT standard        |
| 6   | Mini IoT Project        | Temperature & Distance Monitoring → Alerts on Phone | Integrate sensors, ESP32, web server, optional MQTT |
| 7   | Revision & Notes        | Draw full IoT system diagram                        | End-to-end understanding, ready for bigger projects |

---

### **Extra Tips**

* Keep **one page notes per component**: connections, libraries, example code.
* Test each sensor separately before combining — avoid debugging headache.
* Treat “IoT” like Python functions: Input → Process → Output, but physical/online.
* Use a **breadboard** for safe experimentation.
* Take photos of circuits for reference.

---