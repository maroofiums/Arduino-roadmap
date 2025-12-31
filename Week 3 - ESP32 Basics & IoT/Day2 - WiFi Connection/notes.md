# 🗓️ Week 3 — Day 2

## **ESP32 WiFi Connection**

### 🎯 Day Goal

* ESP32 ko **WiFi se connect**
* **IP address print**
* WiFi ka **flow samajhna** (yeh future IoT ka base hai)

---

## 🔹 Pehle concept clear karo (VERY IMPORTANT)

Arduino UNO:

> Code → Pin → Output

ESP32:

> Code → WiFi → Router → Internet → Cloud

WiFi connect hona matlab:

* Tumhara ESP32 **network ka device** ban gaya

---

## 🔧 Requirements

* ESP32 board
* WiFi (mobile hotspot bhi chalega)
* Arduino IDE

---

## 💻 Day 2 Code — WiFi Connect

```cpp
#include <WiFi.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

void setup() {
  Serial.begin(9600);
  delay(1000);

  Serial.println("Connecting to WiFi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Nothing here for now
}
```

---

## 🔍 Line-by-Line Deep Explanation

### `#include <WiFi.h>`

* ESP32 ki **built-in WiFi library**
* Arduino UNO mein ye exist nahi karti

---

### `const char* ssid`

* WiFi ka **name**
* `const` use kiya → RAM save hoti hai ✔

Best practice 👍

---

### `WiFi.begin(ssid, password);`

* ESP32 router se **handshake start** karta hai

---

### `while (WiFi.status() != WL_CONNECTED)`

Ye **blocking loop** hai:

* Jab tak WiFi connect nahi hota
* Tab tak code aage nahi jata

Beginner ke liye perfect ✔
Later hum **non-blocking** seekhenge

---

### `WiFi.localIP()`

* Router ne jo IP assign ki
* Ye IP future mein:

  * Web server
  * API
  * MQTT
    mein use hogi

---

## 🔹 Serial Monitor Settings

⚠️ **MOST IMPORTANT**

Serial Monitor:

* Baud Rate = **9600**
* Line Ending = **Both NL & CR** (optional)

Agar baud match nahi → garbage output

---

## 🧠 ESP32 vs Arduino UNO (WiFi POV)

| Feature      | Arduino UNO | ESP32      |
| ------------ | ----------- | ---------- |
| WiFi         | ❌           | ✅ Built-in |
| Extra module | Required    | ❌          |
| IP Address   | ❌           | ✅          |
| Cloud access | ❌           | ✅          |

---

## ❌ Common Errors & Fix

### ❌ “Connecting to WiFi… stuck”

✔ SSID spelling check
✔ Password correct?
✔ 2.4 GHz WiFi (ESP32 5GHz support nahi karta)

---

### ❌ Upload error (port busy)

✔ Serial Monitor close
✔ Correct COM port
✔ Correct ESP32 board selected

---

## 🧠 Mentor Honest Advice ❤️

IoT mein:

> **WiFi stable = system stable**

Isliye:

* Mobile hotspot se test karo
* Baad mein home router pe shift

---

## 🔚 Day 2 Summary 

* ESP32 WiFi connect ho gaya
* IP mil gaya
* Ab ESP32 = network device 🌍

---