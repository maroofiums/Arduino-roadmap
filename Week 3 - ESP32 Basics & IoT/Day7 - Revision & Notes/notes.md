## 🔁 Day 7 – Revision

### **Sensor → Input → Logic → Output (Master Table)**

| Sensor / Module | Input Pin      | Data Type       | Logic (Brain)   | Output                    | Real Use        |
| --------------- | -------------- | --------------- | --------------- | ------------------------- | --------------- |
| **Button**      | Digital (GPIO) | HIGH / LOW      | if pressed      | LED / Servo               | Switch, Menu    |
| **LED**         | Digital        | HIGH / LOW      | direct control  | Light ON/OFF              | Indicator       |
| **Servo Motor** | PWM GPIO       | Angle (0–180)   | map / sweep     | Movement                  | Radar, Door     |
| **HC-SR04**     | Trig / Echo    | Time → Distance | if distance < X | LED / Buzzer / Servo stop | Radar, Obstacle |
| **DHT11**       | Digital        | Temp / Humidity | if temp > 30    | LED / Cloud               | Weather         |
| **ESP32 WiFi**  | —              | HTTP / JSON     | Send data       | ThingSpeak                | Cloud logging   |

---

## 🧠 **Radar System Logic (Jo tu bana raha hai)**

Simple words me:

```
Servo sweep kare (0 → 180 → 0)
↓
HC-SR04 distance measure kare
↓
Agar object close ho:
   Servo stop
   LED ON
Else:
   Servo continue
```

Yani:
**Sensor → Decision → Action**

---

## 🔄 Code Thinking Pattern (Ye yaad rakh)

Har ESP32 / Arduino project me ye 4 steps hotay hain:

1️⃣ **Define pins**
2️⃣ **Read input** (sensor / button)
3️⃣ **Apply logic** (if / else)
4️⃣ **Control output** (LED / Servo / Cloud)

Agar koi project samajh na aaye → is pattern pe tod do ✔️

---

## ⚠️ Common Mistakes (Avoid karo)

❌ Random wiring without logic
❌ Direct HC-SR04 Echo to ESP32 (without resistor)
❌ Servo ko delay() ke sath block karna
❌ Sensor value ko print kiye baghair trust kar lena

✅ Always **Serial Monitor se values check** karo
✅ Pehle **local LED test**, phir cloud

---

## 📌 Day 7 Mini Task (Recommended)

👉 Notebook / `notes.md` me likho:

* Har sensor ka **input pin**
* Output kya control karta hai
* Logic condition kya hai

Example:

```
HC-SR04 → distance
if distance < 20cm → LED 
```
---