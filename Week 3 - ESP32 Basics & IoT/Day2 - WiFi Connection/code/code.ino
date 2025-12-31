#include <WiFi.h>

const char* ssid = "Shine-Fiber-*****";
const char* password = "14******";

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

}
