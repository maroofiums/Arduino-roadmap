#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Shine-Fiber-Ahmed";
const char* password = "145343PR";

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

}
