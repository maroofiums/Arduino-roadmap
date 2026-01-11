# **Week 4 – Day 5**

---

## 🧠 What is MQTT?

Think like Python:

* MQTT = **Message Queue Telemetry Transport**
* Lightweight protocol → IoT friendly
* **Two main roles**:

  1. **Publisher** → ESP32 (sensors data bhejta)
  2. **Subscriber** → Mobile / Dashboard / another ESP32 (data receive karta)

---

## 🔌 Hardware

Same as **Day 3/4**:

* DHT11 → GPIO4
* HC-SR04 → TRIG: 5, ECHO: 18
* LED & Servo optional

---

## 🛠️ Requirements

* ESP32
* Arduino IDE
* **PubSubClient Library** → for MQTT
* Broker → [https://test.mosquitto.org](https://test.mosquitto.org) (free public broker)

---

## 🌐 MQTT Concept Flow

```
DHT11/HC-SR04 → ESP32 → Publish → Broker → Subscriber (Mobile / Web / Another ESP32)
```

---

## 🧾 Full Example Code (Publisher)

```cpp
#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11
#define TRIG_PIN 5
#define ECHO_PIN 18

DHT dht(DHTPIN, DHTTYPE);
WiFiClient espClient;
PubSubClient client(espClient);

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";
const char* mqtt_server = "test.mosquitto.org";

long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  return duration * 0.034 / 2;
}

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  dht.begin();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  client.setServer(mqtt_server, 1883);
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP32Client")) {
      Serial.println("Connected to MQTT Broker");
    } else {
      delay(1000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  float temp = dht.readTemperature();
  long distance = getDistance();

  // Publish sensor data
  String payload = "Temperature:" + String(temp) + ",Distance:" + String(distance);
  client.publish("esp32/sensors", payload.c_str());

  Serial.println("Published: " + payload);
  delay(5000);
}
```

---

## 🔍 Step-by-Step Logic

1️⃣ ESP32 connect to WiFi → `WiFi.begin()` <br>
2️⃣ Connect to MQTT broker → `client.connect()` <br>
3️⃣ Read sensors → `dht.readTemperature()` & `getDistance()` <br>
4️⃣ Create payload → `"Temperature:30,Distance:12"` <br>
5️⃣ Publish → `client.publish(topic, payload)` <br>

---

## ✅ Why MQTT?

* **Real IoT standard**
* **Lightweight**, works on low bandwidth
* Decoupled → publisher & subscriber alag devices ho sakte hain

---

## ⚡ Mini Exercise

1. Use another ESP32 / Python script → **subscribe** to `"esp32/sensors"` topic
2. Print values in terminal / dashboard