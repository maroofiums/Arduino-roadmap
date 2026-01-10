#include <WiFi.h>
#include <Servo.h>
#include "DHT.h"

#define LED_PIN 2
#define SERVO_PIN 13
#define DHTPIN 4
#define DHTTYPE DHT11
#define TRIG_PIN 5
#define ECHO_PIN 18

Servo myServo;
DHT dht(DHTPIN, DHTTYPE);
WiFiServer server(80);

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

bool ledState = false;
int servoAngle = 0;

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

  pinMode(LED_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  myServo.attach(SERVO_PIN);
  dht.begin();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;

  String request = client.readStringUntil('\r');
  client.flush();

  if (request.indexOf("/LED=ON") != -1) ledState = true;
  if (request.indexOf("/LED=OFF") != -1) ledState = false;
  if (request.indexOf("/SERVO=OPEN") != -1) servoAngle = 90;
  if (request.indexOf("/SERVO=CLOSE") != -1) servoAngle = 0;

  digitalWrite(LED_PIN, ledState);
  myServo.write(servoAngle);

  float temp = dht.readTemperature();
  long distance = getDistance();

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println();

  client.println("<html><head>");
  client.println("<meta http-equiv='refresh' content='5'>");
  client.println("</head><body>");

  client.println("<h2>ESP32 IoT Control Panel</h2>");

  client.println("<p>Temperature: " + String(temp) + " °C</p>");
  client.println("<p>Distance: " + String(distance) + " cm</p>");

  client.println("<a href=\"/LED=ON\"><button>LED ON</button></a>");
  client.println("<a href=\"/LED=OFF\"><button>LED OFF</button></a><br><br>");

  client.println("<a href=\"/SERVO=OPEN\"><button>Open Servo</button></a>");
  client.println("<a href=\"/SERVO=CLOSE\"><button>Close Servo</button></a>");

  client.println("</body></html>");
  client.stop();
}
