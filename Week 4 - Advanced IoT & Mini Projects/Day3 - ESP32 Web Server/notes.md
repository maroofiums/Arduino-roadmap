
# **Week 4 – Day 3**


Goal simple hai:

> **ESP32 apna khud ka webpage banaye**
> aur us page par **DHT11 + HC-SR04 values live show hon**

Main **deep + step-by-step** samjha raha hoon — jaise Python backend samjhte ho waise hi 😉

---

## 🧠 Big Picture (Architecture)

```
DHT11 / HC-SR04
       ↓
     ESP32
       ↓
   Web Server
       ↓
  Browser (Mobile / Laptop)
```

ESP32 = backend
Browser = frontend
HTML = response (just like FastAPI returning HTML)

---

## 🔌 Hardware Connections (Revision)

### DHT11

| Pin                                              | ESP32  |
| ------------------------------------------------ | ------ |
| VCC                                              | 3.3V   |
| DATA                                             | GPIO 4 |
| GND                                              | GND    |
| ➡ **10kΩ resistor** between VCC & DATA (pull-up) |        |

### HC-SR04

| Pin  | ESP32                         |
| ---- | ----------------------------- |
| VCC  | 5V                            |
| TRIG | GPIO 5                        |
| ECHO | GPIO 18 (via voltage divider) |
| GND  | GND                           |

Voltage divider (important):

```
ECHO ---[1kΩ]--- GPIO18
        |
      [2kΩ]
        |
       GND
```

---

## 🌐 ESP32 Web Server – FULL CODE

> Ye code **ESP32 Dev Module** ke liye hai

```cpp
#include <WiFi.h>
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

#define TRIG_PIN 5
#define ECHO_PIN 18

DHT dht(DHTPIN, DHTTYPE);
WiFiServer server(80);

// 🔐 WiFi credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

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
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  float temp = dht.readTemperature();
  long distance = getDistance();

  client.println("HTTP/1.1 200 OK");
  client.println("Content-type:text/html");
  client.println();

  // ---------- HTML PAGE ----------
  client.println("<!DOCTYPE html><html>");
  client.println("<head>");
  client.println("<meta http-equiv='refresh' content='5'>");
  client.println("<title>ESP32 Sensor Dashboard</title>");
  client.println("<style>");
  client.println("table {border-collapse: collapse; width: 50%;}");
  client.println("th, td {border: 1px solid black; padding: 8px;}");
  client.println("</style>");
  client.println("</head>");

  client.println("<body>");
  client.println("<h2>ESP32 Live Sensor Data</h2>");
  client.println("<table>");
  client.println("<tr><th>Sensor</th><th>Value</th></tr>");
  client.println("<tr><td>Temperature</td><td>" + String(temp) + " °C</td></tr>");
  client.println("<tr><td>Distance</td><td>" + String(distance) + " cm</td></tr>");
  client.println("</table>");
  client.println("</body></html>");

  client.stop();
}
```

---

## 🧩 Line-by-Line Concept (Deep Understanding)

### `WiFiServer server(80);`

➡ Port 80 = HTTP
➡ Just like FastAPI running on port 8000

---

### `WiFi.localIP()`

➡ Ye tumhara **ESP32 ka URL** hai
Browser me likho:

```
http://192.168.x.x
```

---

### HTML Part

```html
<meta http-equiv='refresh' content='5'>
```

➡ Page har **5 seconds auto-refresh**
(Simple live update — JS ke baghair)

---

### Why NOT delay()?

* Delay server ko block karta
* Client hang ho jata
* Web apps me **blocking = bad practice**

---

## ⚠️ Common Problems & Fix

❌ Page blank
➡ Check IP address
➡ Same WiFi network

❌ Temperature NaN
➡ DHT wiring + 10k resistor check

❌ Distance random
➡ Echo voltage divider must

---