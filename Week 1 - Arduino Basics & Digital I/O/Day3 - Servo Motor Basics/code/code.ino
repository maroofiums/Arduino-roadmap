#include <Servo.h>

Servo myServo;

int buttonPin = 2;
int ServoPin = 9;

void setup() {
  myServo.attach(ServoPin);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    myServo.write(90);
  } else {
    myServo.write(0);
  }
}
