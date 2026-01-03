#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

const char* ssid = "Shine-Fiber-****";
const char* password = "145****";

String apiKey = "5GCIAZ****";          
const char* server = "http://api.thingspeak.com/update";

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
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
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  Serial.print("Temperature: "); Serial.print(temp); Serial.print(" °C\t");
  Serial.print("Humidity: "); Serial.println(hum);

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String data = "api_key=" + apiKey +
                  "&field1=" + String(temp) +
                  "&field2=" + String(hum);

    http.begin(server);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    int httpCode = http.POST(data);

    if (httpCode > 0) {
      Serial.println("Data sent successfully!");
    } else {
      Serial.println("Error sending data");
    }

    http.end();
  }

  delay(20000);  
}
