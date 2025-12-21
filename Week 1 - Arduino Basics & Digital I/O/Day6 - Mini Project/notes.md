# 🗓️ **Day 6 – Mini Project**

## **LED + Servo + Ultrasonic Sensor (HC-SR04)**

👉 **Real-world idea:**
“Jaise hi koi cheez paas aaye →
🔔 LED ON
🤖 Servo move (gate open)”

---

## 🧩 **Hardware Connections (MOST IMPORTANT)**

Yahi wo part hai jo code se zyada tough lagta hai — so slow & clear 👇

### 🔹 **HC-SR04 Ultrasonic Sensor**

| Sensor Pin | Arduino UNO |
| ---------- | ----------- |
| VCC        | 5V          |
| GND        | GND         |
| TRIG       | Pin 9       |
| ECHO       | Pin 10      |

---

### 🔹 **Servo Motor**

| Servo Wire      | Arduino |
| --------------- | ------- |
| Red             | 5V      |
| Brown / Black   | GND     |
| Yellow / Orange | Pin 6   |

⚠️ **Tip:** Servo thora current zyada leta hai → agar random move kare to external power better hota hai.

---

### 🔹 **LED**

| LED           | Arduino                   |
| ------------- | ------------------------- |
| Long leg (+)  | Pin 3 (via 220Ω resistor) |
| Short leg (–) | GND                       |

---

## 🧠 **Complete Day-6 Code (Clean & Explained)**

```cpp
#include <Servo.h>

#define trigPin 9
#define echoPin 10
#define ledPin 3

Servo gateServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  gateServo.attach(6);

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

  // Convert to distance (cm)
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 15) {
    digitalWrite(ledPin, HIGH);
    gateServo.write(90);   // open gate
  } else {
    digitalWrite(ledPin, LOW);
    gateServo.write(0);    // close gate
  }

  delay(200);
}
```

---

## ❓ **Now answering your REAL questions (important)**

### ❓ **Why `#define` not variable?**

```cpp
#define trigPin 9
```

✔️ Compile time constant
✔️ Fast
✔️ Less RAM usage

❌ Variable hoti:

```cpp
int trigPin = 9;
```

→ RAM consume hoti (UNO ke paas RAM kam hoti hai)

👉 **Embedded rule:**

> “Pins, constants = `#define` or `const int`”

---

### ❓ **Why `long duration`?**

```cpp
long duration;
```

Because:

* `pulseIn()` **microseconds** return karta hai
* Ye value **int (32767)** se bari ho sakti hai

👉 `long` = zyada range
❌ int = overflow → wrong distance

---

### ❓ **Why NOT heavy `delay()`?**

Servo + sensor + LED = **multiple things at same time**

Agar:

```cpp
delay(2000);
```

🚫 Sensor 2 sec blind
🚫 Servo slow
🚫 Real-time behavior kharab

Isliye:

* Sirf **small delay**
* Aage ja ke **millis()** use karein ge (advanced)

---

### ❓ **Why distance kabhi wrong lagti hai?**

Bilkul normal 😄 reasons:

1️⃣ Temperature effect
2️⃣ Cheap HC-SR04 sensor
3️⃣ Angle of object
4️⃣ Echo noise

👉 Room temp 30.6°C December mein Karachi?
✔️ **Bilkul possible** (AC off ho to)

---

## 🧪 **Virtual Circuit Practice (MUST USE)**

Yeh websites **game changer** hain 🔥

### ✅ **Tinkercad Circuits**

🔹 Arduino + Servo + HC-SR04
🔹 Code + wiring dono
🔹 Beginner friendly

👉 Google karo: **“Tinkercad Circuits Arduino”**

### ✅ **Wokwi**

🔹 Fast
🔹 Pro-level
🔹 ESP32 bhi

---

## 🧠 **Honest Mentor Advice**

* Hardware confusion = **normal**
* Wiring seekhne mein **time lagta hai**
* Pehle **Tinkercad**, phir real board
* Code se pehle **pins draw karo paper pe**

---

## 🧾 **Quick Summary / Tip**

> 🔑 Arduino mein **wiring clarity = 50% success**
> 🔑 `pulseIn → long`
> 🔑 `#define` = memory efficient
> 🔑 Real sensors kabhi 100% accurate nahi hote