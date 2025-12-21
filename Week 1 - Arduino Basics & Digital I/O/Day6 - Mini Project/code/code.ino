#include <Servo.h>

#define trigPin 9
#define echoPin 10
#define ledPin 3
#define servoPin 6

Servo radarServo;

long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000); 
  if (duration == 0) return -1;

  return duration * 0.034 / 2;
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  radarServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  int distance;
  bool objectDetected = false;

  for (int angle = 0; angle <= 180; angle += 2) {
    radarServo.write(angle);
    delay(20);

    distance = getDistance();
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print("  Distance: ");
    Serial.println(distance);

    if (distance > 0 && distance < 20) {
      digitalWrite(ledPin, HIGH);
      objectDetected = true;
      break;   
    }
  }

  if (!objectDetected) {
    for (int angle = 180; angle >= 0; angle -= 2) {
      radarServo.write(angle);
      delay(20);

      distance = getDistance();
      Serial.print("Angle: ");
      Serial.print(angle);
      Serial.print("  Distance: ");
      Serial.println(distance);

      if (distance > 0 && distance < 20) {
        digitalWrite(ledPin, HIGH);
        objectDetected = true;
        break;
      }
    }
  }

  if (!objectDetected) {
    digitalWrite(ledPin, LOW);
  }
}
