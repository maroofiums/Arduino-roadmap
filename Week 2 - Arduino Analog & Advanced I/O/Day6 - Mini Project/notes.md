

# 🗓️ Week 2 — Day 6

## 🚨 **Mini Project: Object Detection Alarm System**

### 🎯 Project Goal (simple words)

* **HC-SR04** object detect kare
* Agar object paas aaye
  👉 **LED ON**
  👉 **Servo move**
  👉 **Serial Monitor pe ALERT**

Ye bilkul **real security system** ka base hai.

---

## 🧠 System Thinking (VERY IMPORTANT)

Socho is project ko is flow mein:

```
Object
  ↓
Ultrasonic Sensor
  ↓
Distance Calculation
  ↓
IF condition
  ↓
LED + Servo + Serial Alert
```

Agar tum ye flow samajh gaye → 70% IoT clear ✅

---

## 🔧 Components Used

* Arduino UNO
* HC-SR04
* Servo motor
* LED + resistor (220Ω)
* Jumper wires

---

## 🔌 Hardware Connections

### 🔵 HC-SR04

| Sensor Pin | Arduino |
| ---------- | ------- |
| VCC        | 5V      |
| GND        | GND     |
| TRIG       | Pin 9   |
| ECHO       | Pin 10  |

---

### 🟡 Servo

| Wire   | Arduino |
| ------ | ------- |
| Red    | 5V      |
| Brown  | GND     |
| Yellow | Pin 6   |

---

### 🔴 LED

| LED           | Arduino              |
| ------------- | -------------------- |
| Long leg (+)  | Pin 3 (via resistor) |
| Short leg (–) | GND                  |

---

## 💻 Complete Code (Mini Project)

```cpp
#include <Servo.h>

#define trigPin 9
#define echoPin 10
#define ledPin 3
#define servoPin 6

Servo alarmServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  alarmServo.attach(servoPin);
  alarmServo.write(0);

  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;

  // Ultrasonic trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  duration = pulseIn(echoPin, HIGH);

  // Convert to distance
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Alarm Logic
  if (distance > 0 && distance < 15) {
    digitalWrite(ledPin, HIGH);
    alarmServo.write(90);

    Serial.println("⚠ ALERT: Object Detected!");
  } else {
    digitalWrite(ledPin, LOW);
    alarmServo.write(0);
  }

  delay(300);
}
```

---

## 🔍 Deep Explanation (Step-by-Step)

### 1️⃣ `#define` kyun?

```cpp
#define trigPin 9
```

👉 Best practice

* Code readable hota hai
* Pin change karna easy
* RAM save hoti hai (UNO mein RAM kam hoti hai)

---

### 2️⃣ `long duration` kyun?

```cpp
long duration;
```

👉 `pulseIn()` **microseconds** return karta hai
👉 Value badi ho sakti hai
👉 `int` overflow kar sakta hai

Isliye:
✔ `long` = safe

---

### 3️⃣ `pulseIn()` ka magic

```cpp
duration = pulseIn(echoPin, HIGH);
```

* Echo HIGH rehne ka time measure
* Ye time = sound ka travel time

---

### 4️⃣ Distance formula

```cpp
distance = duration * 0.034 / 2;
```

* `0.034` = sound speed
* `/2` = round trip correction

---

### 5️⃣ Decision logic (real automation)

```cpp
if (distance < 15)
```

Ye **threshold** tum customize kar sakte ho:

* 10 cm → strict security
* 20 cm → normal alarm
* 50 cm → warning system

---

## ❌ Common Errors (tum avoid karo)

❌ Servo ko non-PWM pin pe lagana
❌ LED without resistor
❌ Serial.begin() bhool jana
❌ Ultrasonic ka GND loose hona

---

## 🌍 Real-Life Use Cases

* Smart gate
* Intruder alarm
* Automatic door
* Parking alert system

---

## 🔚 Day 6 Summary 

* Sensor detect karta hai
* IF condition decision leti hai
* Actuator react karta hai

