#include <WiFi.h>
#include <ESP32WebServer.h>
#include <Servo.h>

const char* ssid = "YOUR_WIFI";        // Replace with your WiFi SSID
const char* password = "YOUR_PASS";    // Replace with your WiFi password

#define LED_PIN 2
#define SERVO_PIN 4

Servo myServo;
ESP32WebServer server(80); // Web server on port 80

String htmlPage = R"rawliteral(
<!DOCTYPE html>
<html>
  <head>
    <title>ESP32 Remote Control</title>
  </head>
  <body>
    <h1>ESP32 Web Server</h1>
    <button onclick="fetch('/led/on')">LED ON</button>
    <button onclick="fetch('/led/off')">LED OFF</button>
    <button onclick="fetch('/servo/open')">Servo Open</button>
    <button onclick="fetch('/servo/close')">Servo Close</button>
  </body>
</html>
)rawliteral";

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
  Serial.begin(115200);

  // Pin setup
  pinMode(LED_PIN, OUTPUT);
  myServo.attach(SERVO_PIN);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Setup server routes
  setupServer();
}

void loop() {
  server.handleClient();  // Listen and respond to web requests
}
