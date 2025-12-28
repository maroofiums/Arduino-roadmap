#include <Servo.h>

#define trigPin 9
#define echoPin 10
#define ledPin 13
#define servoPin 6

Servo alarmServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  alarmServo.attach(servoPin);
  alarmServo.write(0);

  Serial.begin(9600);
}

void loop() {
  long duration;
  int distance;

  // Ultrasonic trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  duration = pulseIn(echoPin, HIGH);

  // Convert to distance
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Alarm Logic
  if (distance > 0 && distance < 15) {
    digitalWrite(ledPin, HIGH);
    alarmServo.write(90);

    Serial.println("⚠ ALERT: Object Detected!");
  } else {
    digitalWrite(ledPin, LOW);
    alarmServo.write(0);
  }

  delay(300);
}
