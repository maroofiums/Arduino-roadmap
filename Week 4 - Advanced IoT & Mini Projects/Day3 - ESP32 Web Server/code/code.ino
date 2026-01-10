#include <WiFi.h>
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

#define TRIG_PIN 5
#define ECHO_PIN 18

DHT dht(DHTPIN, DHTTYPE);
WiFiServer server(80);

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
