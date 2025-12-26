#include "DHT.h"

#define DHTPIN 7
#define DHTTYPE DHT11
#define LEDPIN 3

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();  // °C
  float hum = dht.readHumidity();      // %

  if (isnan(temp) || isnan(hum)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C  |  Humidity: ");
  Serial.print(hum);
  Serial.println(" %");

  // Conditional logic
  if (temp > 30.0) {
    digitalWrite(LEDPIN, HIGH);  // LED ON
  } else {
    digitalWrite(LEDPIN, LOW);   // LED OFF
  }

  delay(2000); // Wait 2 seconds before next read
}
