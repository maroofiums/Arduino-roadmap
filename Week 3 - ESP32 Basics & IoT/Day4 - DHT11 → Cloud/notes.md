# 🟦 Day 4: DHT11 → ThingSpeak (Cloud Logging)

### 🎯 Goal (simple words)

* DHT11 se **temperature + humidity** read karna
* ESP32 ke through **ThingSpeak cloud** par bhejna
* Matlab: *Sensor → Internet → Dashboard*

Ye **real IoT** hai 🔥

---

## 🧠 Big Picture (pehle flow samjho)

```
DHT11
  ↓
ESP32
  ↓  (WiFi)
HTTP POST
  ↓
ThingSpeak Cloud
  ↓
Graph / Data Log
```

Agar ye flow clear hai → code aadha samajh aa gaya.

---

## 1️⃣ ThingSpeak kya hota hai?

* Free IoT cloud
* Data store karta hai
* Graphs automatically banata hai

Tumhari zimmedari:

* **API KEY** use karna
* Sahi format mein data bhejna

---

## 2️⃣ Required Libraries

```cpp
#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"
```

### Explanation:

* `WiFi.h` → internet
* `HTTPClient.h` → POST request
* `DHT.h` → DHT11 sensor

👉 Honest advice:
Library version mismatch se error aata hai, isliye **DHT by Adafruit** use karo.

---

## 3️⃣ Pin & Sensor Setup

```cpp
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
```

### Simple words:

* DHT data pin → GPIO 4
* Sensor type → DHT11
* `dht` object bana

---

## 4️⃣ WiFi + ThingSpeak Details

```cpp
const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASS";

String apiKey = "YOUR_THINGSPEAK_API_KEY";
const char* server = "http://api.thingspeak.com/update";
```

### Important concept:

* **API Key = password of your channel**
* Galat key → data reject

⚠️ API key **GitHub pe public mat dalna**

---

## 5️⃣ Setup Function

```cpp
void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  dht.begin();

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi Connected");
}
```

Yahan koi magic nahi:

* Serial
* WiFi connect
* DHT start

---

## 6️⃣ Main Logic (🔥 IMPORTANT)

```cpp
void loop() {

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
```

### Sensor read:

* `float` kyun?
  → Temperature decimal hota hai (30.5 etc)

👉 Best practice:
Agar `NaN` aaye → sensor wiring check karo.

---

## 7️⃣ HTTP POST to ThingSpeak

```cpp
  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;

    String data = "api_key=" + apiKey +
                  "&field1=" + String(temp) +
                  "&field2=" + String(hum);

    http.begin(server);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    int httpCode = http.POST(data);
```

### Line-by-line breakdown:

| Line          | Matlab                               |
| ------------- | ------------------------------------ |
| `data`        | Form format (ThingSpeak requirement) |
| `field1`      | Temperature                          |
| `field2`      | Humidity                             |
| `http.POST()` | Data cloud ko bheja                  |

---

## 8️⃣ Response & Cleanup

```cpp
    if (httpCode > 0) {
      Serial.println("Data sent successfully");
    } else {
      Serial.println("Error sending data");
    }

    http.end();
  }

  delay(20000);
}
```

### Why 20 seconds delay?

ThingSpeak rule:

> **1 update / 15 sec**

❌ Zyada fast bhejo → block ho jaoge

---

## 🧪 Output (ThingSpeak Dashboard)

* Live graph
* Date + time ke sath data
* CSV export

Tum officially **IoT developer** ban chuke ho 😎

---

## ⚠️ Common Mistakes (100% log yahin phanste)

❌ Delay kam rakhna
❌ `http.end()` bhoolna
❌ API key galat
❌ DHT power 5V dena (ESP32 ke liye 3.3V best)

---

## 🧠 Real-World Use

* Weather station
* Server room monitoring
* Smart agriculture
* ML ke liye dataset collection 👀

---

