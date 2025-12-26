

# 🗓️ Week 2 — Day 4: DHT11 → Conditional LED

## 🎯 Objectives

1. DHT11 sensor se **temperature & humidity** read karna
2. Conditional logic use karna (`if/else`)
3. LED ON if temperature threshold exceed kare
4. Serial monitor pe debug karna

---

## 🔧 Hardware Required

* Arduino UNO
* DHT11 sensor
* LED + 220Ω resistor
* Jumper wires
* Breadboard

---

## 🔌 Hardware Connections

### DHT11

* VCC → 5V
* GND → GND
* DATA → Pin 7 (with 10k pull-up resistor to VCC optional)

### LED

* Long leg (+) → Pin 3
* Short leg (−) → 220Ω resistor → GND

---

## 💻 Code

```cpp
#include "DHT.h"

#define DHTPIN 7
#define DHTTYPE DHT11
#define LEDPIN 3

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();  // °C
  float hum = dht.readHumidity();      // %

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C  |  Humidity: ");
  Serial.print(hum);
  Serial.println(" %");

  // Conditional logic
  if (temp > 30.0) {
    digitalWrite(LEDPIN, HIGH);  // LED ON
  } else {
    digitalWrite(LEDPIN, LOW);   // LED OFF
  }

  delay(2000); // Wait 2 seconds before next read
}
```

---

## 🧩 Code Deep Explanation

### 1️⃣ DHT Library

```cpp
#include "DHT.h"
DHT dht(DHTPIN, DHTTYPE);
dht.begin();
```

* Simplifies reading sensor
* Handles timing & data protocol

---

### 2️⃣ `readTemperature()` & `readHumidity()`

```cpp
float temp = dht.readTemperature();
float hum = dht.readHumidity();
```

* Returns float values
* NaN check is important → sensor read failure handling

---

### 3️⃣ Conditional Logic

```cpp
if (temp > 30.0) {
  digitalWrite(LEDPIN, HIGH);
} else {
  digitalWrite(LEDPIN, LOW);
}
```

* Temperature threshold → LED ON/OFF
* Core IoT principle: **Sensor → Condition → Action**

---

### 4️⃣ Serial Debug

```cpp
Serial.print("Temperature: ");
```

* Always visualize sensor data
* Helps in tuning thresholds

---

### 5️⃣ Delay

```cpp
delay(2000);
```

* Sensor needs **time between reads**
* Human-readable Serial output

---
