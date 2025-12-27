

# 🗓️ Week 2 — Day 5

## **HC-SR04 + Servo**

**Object detected → Servo moves**

Ye day **real automation ka heart** hai:
👉 *Sensor detect kare*
👉 *Decision ho*
👉 *Actuator move kare*

---

## 🎯 Goal (simple words)

* Ultrasonic sensor se **distance measure**
* Agar object paas aaye → **Servo move**
* Warna servo normal position pe rahe

---

## 🔧 Hardware Required

* Arduino UNO
* HC-SR04 Ultrasonic sensor
* Servo motor (SG90)
* Jumper wires

---

## 🔌 Hardware Connections (IMPORTANT)

### 🟦 HC-SR04

| HC-SR04 Pin | Arduino |
| ----------- | ------- |
| VCC         | 5V      |
| GND         | GND     |
| TRIG        | Pin 9   |
| ECHO        | Pin 10  |

⚠️ **TRIG always OUTPUT**, **ECHO always INPUT**

---

### 🟨 Servo Motor

| Servo Wire      | Arduino |
| --------------- | ------- |
| Red             | 5V      |
| Brown / Black   | GND     |
| Yellow / Orange | Pin 6   |

⚠️ Servo **PWM pin** pe lagta hai (UNO pe 3,5,6,9,10,11)

---

## 💻 Code (Clean & Beginner-Friendly)

```cpp
#include <Servo.h>

#define trigPin 9
#define echoPin 10
#define servoPin 6

Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.attach(servoPin);
  myServo.write(0);   // start position

  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;

  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);

  // Convert to distance
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Decision logic
  if (distance > 0 && distance < 15) {
    myServo.write(90);   // move servo
  } else {
    myServo.write(0);    // reset servo
  }

  delay(300);
}
```

---

## 🧠 Deep Explanation (Ye part GOLD hai)

### 1️⃣ Ultrasonic ka logic

HC-SR04 ka kaam:

* TRIG → sound bhejta hai
* ECHO → sound wapas aane ka time batata hai

```cpp
duration = pulseIn(echoPin, HIGH);
```

⏱️ **pulseIn()**

* HIGH signal ka time (microseconds) measure karta hai
* Isi time se distance calculate hoti hai

---

### 2️⃣ Distance formula

```cpp
distance = duration * 0.034 / 2;
```

Why?

* Sound speed ≈ **0.034 cm/µs**
* `/2` kyun?
  → Sound **ja ke wapas** aati hai

---

### 3️⃣ Servo logic

```cpp
myServo.write(90);
```

Servo angles:

* `0` → left
* `90` → center
* `180` → right

Servo internally **PWM signals** samajhta hai
Isliye **Servo.h library** use karte hain

---

### 4️⃣ Condition (Real IoT logic)

```cpp
if (distance < 15)
```

Ye threshold tum control karte ho:

* 10 cm → very near
* 20 cm → normal gate
* 50 cm → warning system

---

## ❌ Common Mistakes (Avoid karo)

❌ Servo ko random pin pe lagana
❌ ECHO ko OUTPUT banana
❌ Servo ko laptop USB se power dena (sometimes weak)
❌ Distance check ke bina servo move karna

---

## ✅ Best Practice

✔ Always print distance on Serial
✔ Start servo from known position
✔ Use small delays (300–500ms)

---

## 🔥 Real-World Examples

* Automatic gate
* Smart dustbin
* Parking barrier
* Security system

---
