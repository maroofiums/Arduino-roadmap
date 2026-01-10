# Week4 Day2

Yaha hum **DHT11** ka temperature check karenge aur agar temp > 30°C ho to **LED aur buzzer** ON karenge.

---

## 🔌 Connections (ESP32 + LED + Buzzer + DHT11)

| Component       | Pin        | Notes                              |
| --------------- | ---------- | ---------------------------------- |
| DHT11 VCC       | 3.3V       | with 10kΩ pull-up resistor on data |
| DHT11 Data      | GPIO 4     | Digital                            |
| DHT11 GND       | GND        | Common ground                      |
| LED             | GPIO 2     | + resistor (220Ω)                  |
| Buzzer (active) | GPIO 15    | Optional, + resistor if needed     |
| GND             | Common GND |                                    |

---

## 🧾 Full Working Code

```cpp
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

#define LED_PIN 2
#define BUZZER_PIN 15

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("DHT11 Error!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    // ---------- Threshold Alert ----------
    if (temperature > 30.0) {
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(BUZZER_PIN, HIGH);
      Serial.println("Alert! Temperature > 30°C");
    } else {
      digitalWrite(LED_PIN, LOW);
      digitalWrite(BUZZER_PIN, LOW);
    }
  }

  delay(2000); // DHT11 cooldown
}
```

---

## 🧠 Step-by-Step Logic

1️⃣ **Read DHT11** → temperature<br>
2️⃣ **Check if temp > 30°C** → conditional logic (`if`)<br>
3️⃣ **Activate outputs** → LED + Buzzer<br>
4️⃣ **Else** → Turn off outputs<br>

> Ye simple **event-driven logic** ka basic example hai.

---
