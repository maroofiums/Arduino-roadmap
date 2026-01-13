#include "DHT.h"

// Pins
#define DHTPIN 15
#define DHTTYPE DHT11

#define TRIG 2
#define ECHO 4

#define GREEN 12
#define YELLOW 13
#define RED 14

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
}

void loop() {
  // ---- DHT11 Read ----
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // ---- Temp LED Logic ----
  if (temp < 25) {
    digitalWrite(GREEN, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);
  } else if (temp < 30) {
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(RED, LOW);
  } else {
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, HIGH);
  }

  // ---- Ultrasonic Sensor ----
  long duration, distance;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = (duration * 0.0343) / 2; // cm

  Serial.print("Temp: "); Serial.print(temp);
  Serial.print("°C, Hum: "); Serial.print(hum);
  Serial.print("%, Distance: "); Serial.print(distance); Serial.println(" cm");

  // ---- Proximity Alert ----
  if (distance < 50) {
    digitalWrite(GREEN, HIGH); // example: Green LED blinks for proximity
    delay(200);
    digitalWrite(GREEN, LOW);
    delay(200);
  }

  delay(1000); // wait 1 second
}
