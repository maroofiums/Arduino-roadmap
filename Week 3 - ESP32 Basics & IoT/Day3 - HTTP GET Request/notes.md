

# 🗓️ Week 3 — Day 3

## **ESP32 → HTTP GET Request**

### 🎯 Day Goal

* ESP32 se **internet API call**
* **HTTP GET** samajhna
* Response **Serial Monitor** pe print karna
* IoT ka **client-side concept** clear karna

---

## 🧠 Pehle concept (VERY IMPORTANT)

Python mein tum ne ye kiya hoga:

```python
import requests
r = requests.get("https://api.example.com/data")
print(r.text)
```

ESP32 mein same cheez hoti hai, bas syntax different:

```
ESP32 → WiFi → HTTP Client → Server → Response
```

ESP32 yahan **client** hota hai.

---

## 🔧 Requirements

* ESP32 (WiFi connected – Day 2 done ✅)
* Internet
* Arduino IDE

---

## 🌐 Test API (Safe & Free)

Hum use karenge:

```
http://worldtimeapi.org/api/timezone/Asia/Karachi
```

Ye API:

* Free hai
* No API key
* Simple JSON return karti hai

---

## 💻 Day 3 Code — HTTP GET

```cpp
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

void setup() {
  Serial.begin(9600);
  delay(1000);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");

  // HTTP GET Request
  HTTPClient http;
  String url = "http://worldtimeapi.org/api/timezone/Asia/Karachi";

  http.begin(url);
  int httpCode = http.GET();

  if (httpCode > 0) {
    String payload = http.getString();
    Serial.println("Response:");
    Serial.println(payload);
  } else {
    Serial.println("Error in HTTP request");
  }

  http.end();
}

void loop() {
  // nothing here
}
```

---

## 🔍 Deep Explanation (Step-by-Step)

### 1️⃣ `#include <HTTPClient.h>`

* Ye library **ESP32 ko browser bana deti hai**
* GET, POST, headers sab handle karti hai

---

### 2️⃣ `HTTPClient http;`

* Python ke `requests` object jaisa
* Ek HTTP session start karta hai

---

### 3️⃣ `http.begin(url);`

* ESP32 ko batata hai:

  > “Is server pe jana hai”

---

### 4️⃣ `int httpCode = http.GET();`

* GET request send hoti hai
* Return hota hai **HTTP status code**

Common codes:

* `200` → OK ✅
* `404` → Not Found
* `500` → Server error

---

### 5️⃣ `http.getString()`

* Server ka **response body**
* Mostly **JSON**

Tum abhi sirf print karo — parsing Day 4–5 mein aayegi.

---

### 6️⃣ `http.end();`

⚠️ **VERY IMPORTANT**

* Connection close karta hai
* Memory free karta hai

ESP32 mein RAM precious hoti hai.

---

## 📟 Serial Monitor Output (Example)

```json
{
  "timezone":"Asia/Karachi",
  "datetime":"2025-01-01T10:30:00+05:00",
  "day_of_week":3
}
```

Agar ye dikh gaya → **MISSION SUCCESS 🎯**

---

## ❌ Common Errors & Fix

### ❌ HTTP request fail

✔ WiFi connected?
✔ URL correct?
✔ `http://` use karo (https advanced hai abhi)

---

### ❌ Garbage output

✔ Baud rate **9600** match
✔ Serial Monitor closed during upload

---

