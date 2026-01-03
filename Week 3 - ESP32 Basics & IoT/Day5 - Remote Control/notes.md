

# 🟦 Day 5 – ESP32 Web Server (Remote Control LED/Servo)

### 🎯 Goal

* ESP32 ka **web server** chalana
* Webpage → buttons → LED ya Servo control
* Real-time interaction → **IoT action**

---

## 1️⃣ Required Libraries

```cpp
#include <WiFi.h>
#include <ESP32WebServer.h>
#include <Servo.h>
```

* `WiFi.h` → Connect to internet/router
* `ESP32WebServer.h` → Host web server
* `Servo.h` → Servo control

---

## 2️⃣ Pin Setup

| Component | ESP32 Pin |
| --------- | --------- |
| LED       | 2         |
| Servo     | 4         |

```cpp
#define LED_PIN 2
#define SERVO_PIN 4

Servo myServo;
ESP32WebServer server(80); // Port 80 = default HTTP
```

---

## 3️⃣ WiFi Connect

```cpp
const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASS";

void setup() {
  Serial.begin(115200);
  myServo.attach(SERVO_PIN);
  pinMode(LED_PIN, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}
```

* ESP32 ko router se connect karo
* Serial Monitor → IP address check karo (ye website ka address hoga)

---

## 4️⃣ Webpage HTML

* Simple webpage + 2 buttons → LED ON/OFF

```cpp
String htmlPage = R"rawliteral(
<!DOCTYPE html>
<html>
  <head><title>ESP32 Remote Control</title></head>
  <body>
    <h1>ESP32 Web Server</h1>
    <button onclick="fetch('/led/on')">LED ON</button>
    <button onclick="fetch('/led/off')">LED OFF</button>
    <button onclick="fetch('/servo/open')">Servo Open</button>
    <button onclick="fetch('/servo/close')">Servo Close</button>
  </body>
</html>
)rawliteral";
```

* `fetch('/led/on')` → server endpoint
* `fetch` = modern JS method to call ESP32 routes

---

## 5️⃣ Define Server Routes

```cpp
void handleRoot() {
  server.send(200, "text/html", htmlPage);
}

void ledOn() {
  digitalWrite(LED_PIN, HIGH);
  server.send(200, "text/plain", "LED ON");
}

void ledOff() {
  digitalWrite(LED_PIN, LOW);
  server.send(200, "text/plain", "LED OFF");
}

void servoOpen() {
  myServo.write(90);  // open position
  server.send(200, "text/plain", "Servo Open");
}

void servoClose() {
  myServo.write(0);   // close position
  server.send(200, "text/plain", "Servo Close");
}
```

---

## 6️⃣ Setup Server Endpoints

```cpp
void setupServer() {
  server.on("/", handleRoot);
  server.on("/led/on", ledOn);
  server.on("/led/off", ledOff);
  server.on("/servo/open", servoOpen);
  server.on("/servo/close", servoClose);
  
  server.begin();
  Serial.println("HTTP server started");
}

void setup() {
  // WiFi + Servo + LED code here
  setupServer();
}
```

---

## 7️⃣ Main Loop

```cpp
void loop() {
  server.handleClient(); // Listen for client requests
}
```

---

## 8️⃣ How it Works

1. ESP32 WiFi connect hota hai
2. ESP32 port 80 pe **web server host** karta hai
3. Browser → `http://ESP32_IP/` open karo
4. Button press → ESP32 route trigger → LED ya Servo move

---

### ⚠️ Notes / Best Practices

* LED → simple HIGH/LOW
* Servo → use `write()` 0° / 90° / 180°
* Browser multiple tabs → server handle kar lega
* Serial Monitor → debugging ke liye open rakho

