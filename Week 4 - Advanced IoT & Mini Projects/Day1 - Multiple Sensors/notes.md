

## Week4 Day1

**DHT11** se:

* Temperature
* Humidity

**HC-SR04** se:

* Distance

👉 **Sab values ek hi time pe Serial Monitor par show karni hain**
without confusion, without wrong readings.

---

## 🧠 Core Problem (jo usually confuse karta hai)

> “Ek sensor read ho jata hai, doosra ghalat values deta hai”

Reason:

* Sensors **different timing** use karte hain
* DHT11 slow hota hai
* HC-SR04 fast hota hai

👉 Is liye **proper delay + order** zaroori hota hai

---

## 🔌 Connections (ESP32)

### DHT11

| DHT11    | ESP32             |
| -------- | ----------------- |
| VCC      | 3.3V              |
| DATA     | GPIO 4            |
| GND      | GND               |
| DATA–VCC | **10kΩ resistor** |

### HC-SR04 (Voltage safe)

| HC-SR04 | ESP32                          |
| ------- | ------------------------------ |
| VCC     | 5V                             |
| TRIG    | GPIO 5                         |
| ECHO    | GPIO 18 (via 10k + 1k divider) |
| GND     | GND                            |

---

## 🧾 Full Working Code (ESP32)

```cpp
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

#define TRIG_PIN 5
#define ECHO_PIN 18

DHT dht(DHTPIN, DHTTYPE);

long duration;
float distance;

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  dht.begin();
}

void loop() {

  // ---------- HC-SR04 ----------
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  // ---------- DHT11 ----------
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // ---------- DISPLAY ----------
  Serial.println("------ SENSOR DATA ------");

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT11 Error!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.println("-------------------------\n");

  delay(2000); // VERY IMPORTANT
}
```

---

## 🔍 Step-by-Step Logic (Samajhna zaroori hai)

### 1️⃣ HC-SR04 pehle kyun?

* Fast sensor
* Microseconds me kaam karta hai
* DHT ko disturb nahi karta

### 2️⃣ DHT11 baad me kyun?

* Slow sensor
* Har 1–2 seconds me read hota hai
* Jaldi read karoge → **NaN / wrong values**

### 3️⃣ `delay(2000)` kyun?

* DHT11 ka **cooldown time**
* Best practice hai

---
