#include <ESP32Servo.h>

// Pins
#define SERVO_PIN 4
#define TRIG_PIN 5
#define ECHO_PIN 18
#define LED_PIN 2

Servo radarServo;

void setup() {
  Serial.begin(115200);

  // Pin setup
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  radarServo.attach(SERVO_PIN); // Attach servo to pin
}

// Function to read distance from HC-SR04
long readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000); // 30ms timeout
  long distance = duration * 0.034 / 2;
  return distance;
}

void loop() {
  // Sweep 0 -> 180
  for (int angle = 0; angle <= 180; angle += 5) {
    radarServo.write(angle);
    delay(20); // Smooth movement
    long distance = readDistanceCM();

    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print("° | Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance > 0 && distance < 20) { // Object within 20 cm
      digitalWrite(LED_PIN, HIGH);      // Turn on LED
      radarServo.write(angle);           // Lock servo
      Serial.println(">>> Object Detected! <<<");
      delay(1000);                       // Pause 1 second
    } else {
      digitalWrite(LED_PIN, LOW);
    }
  }

  // Sweep 180 -> 0
  for (int angle = 180; angle >= 0; angle -= 5) {
    radarServo.write(angle);
    delay(20);
    long distance = readDistanceCM();

    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print("° | Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance > 0 && distance < 20) {
      digitalWrite(LED_PIN, HIGH);
      radarServo.write(angle);
      Serial.println(">>> Object Detected! <<<");
      delay(1000);
    } else {
      digitalWrite(LED_PIN, LOW);
    }
  }
}
