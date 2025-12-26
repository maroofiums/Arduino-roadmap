#include <Servo.h>

Servo myServo;

#define buttonPin 2
#define ledPin 3
#define servoPin 6

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  myServo.attach(servoPin);
  myServo.write(0); 
  Serial.begin(9600);
}

void loop(){
  if (digitalRead(buttonPin) == LOW){
    Serial.println("Button Pressed");
    digitalWrite(ledPin, HIGH);
    myServo.write(360);
    delay(200);
    
    
  }
  else{
    digitalWrite(ledPin, LOW);
    myServo.write(0);
    delay(500);
  }
}