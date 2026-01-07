#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

#define TRIG_PIN 5
#define ECHO_PIN 18

DHT dht(DHTPIN, DHTTYPE);

long duration;
float distance;

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  dht.begin();
}

void loop() {

  // ---------- HC-SR04 ----------
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  // ---------- DHT11 ----------
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // ---------- DISPLAY ----------
  Serial.println("------ SENSOR DATA ------");

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("DHT11 Error!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.println("-------------------------\n");

  delay(2000); // VERY IMPORTANT
}
