# 🗓️ Week 3 — Day 1

## **ESP32 Blink & GPIO Pins**

### 🎯 Day Goal

1. ESP32 ka **onboard LED blink**
2. ESP32 ke **GPIO pins samajhna**
3. **ESP32 vs Arduino UNO** ka clear difference

---

## 🔹 Sab se pehle: ESP32 kya hai?

Simple words mein:

> **ESP32 = Arduino + WiFi + Bluetooth (sab ek chip mein)**

Arduino UNO:

* Sirf control
* Offline

ESP32:

* Control + Internet
* Real IoT 💡

---

## 🔹 ESP32 setup (IMPORTANT CHECK)

Arduino IDE mein ye ensure karo:

### 1️⃣ Board install

```
Tools → Board → ESP32 Arduino → ESP32 Dev Module
```

(Agar ESP32 boards install nahi hain, pehle Boards Manager se install karna hota hai — but tum bol chuke ho IDE ready hai 👍)

---

## 🔹 ESP32 Onboard LED (CONFUSION CLEAR)

⚠️ **Arduino UNO**

* Onboard LED = **Pin 13**

⚠️ **ESP32**

* Onboard LED **fix nahi hota**
* Zyada tar boards mein:

  * GPIO **2** ya **LED_BUILTIN**

Best practice:
👉 Pehle `LED_BUILTIN` try karo
👉 Agar blink na ho → GPIO 2 use karo

---

## 💻 Day 1 Code — ESP32 Blink

### ✅ Version 1 (Recommended)

```cpp
#define LED_PIN 2   // ESP32 onboard LED (mostly GPIO 2)

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);

  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
```

⏱️ Result:

* LED ON → 1 sec
* LED OFF → 1 sec

---

## 🔍 Code Deep Explanation

### `#define LED_PIN 2`

* Pin ko naam diya
* Kal pin change karni ho → sirf ek line change

👉 **Best practice**

---

### `pinMode(LED_PIN, OUTPUT)`

* ESP32 ko bataya:

  > “Is pin se main signal bhejunga”

---

### `digitalWrite(HIGH / LOW)`

* HIGH = 3.3V (ESP32)
* LOW = 0V

⚠️ **ESP32 is 3.3V, NOT 5V**
Ye bohot important difference hai.

---

## 🔹 ESP32 vs Arduino UNO (VERY IMPORTANT TABLE)

| Feature     | Arduino UNO | ESP32           |
| ----------- | ----------- | --------------- |
| Voltage     | 5V          | 3.3V ⚠️         |
| CPU         | 8-bit       | 32-bit          |
| Clock       | 16 MHz      | 240 MHz 🔥      |
| WiFi        | ❌           | ✅               |
| Bluetooth   | ❌           | ✅               |
| GPIO pins   | Limited     | More & flexible |
| Analog pins | Fixed A0–A5 | Almost all GPIO |
| PWM         | Limited     | Almost all GPIO |

---

## 🔹 ESP32 GPIO Pins (Basics)

ESP32 ke pins **smart** hain, but kuch rules hain:

### ✅ Safe GPIO (Beginner friendly)

* GPIO 2
* GPIO 4
* GPIO 5
* GPIO 18
* GPIO 19
* GPIO 21
* GPIO 22
* GPIO 23

### ❌ Avoid for now

* GPIO 0 (boot mode)
* GPIO 1, 3 (Serial)
* GPIO 6–11 (flash memory)

👉 Beginner ho → **safe pins hi use karo**

---

## 🔹 Common Beginner Confusions (Clear karta hoon)

### ❓ “UNO ka code ESP32 pe kyun nahi chala?”

* Voltage different (5V vs 3.3V)
* Pins different
* Speed different

---

### ❓ “delay() ESP32 pe bhi use hota hai?”

✔ Yes (abhi ke liye)
Later:

* `millis()`
* FreeRTOS (advanced)

---

## 🧠 Mentor Honest Advice ❤️

ESP32 powerful hai, lekin:

> **Power ke sath discipline chahiye**

* Galat pin → board boot hi nahi karega
* 5V directly GPIO pe → ESP32 dead 😬

Isliye:
✔ Datasheet habit banao
✔ Safe pins se start karo

---
