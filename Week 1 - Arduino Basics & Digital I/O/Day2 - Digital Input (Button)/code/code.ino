int buttonPin = 2;
int lightPin = 13;

void setup() {
  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(lightPin,OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    digitalWrite(lightPin,HIGH);
  } else {
    digitalWrite(lightPin,LOW);
  }
  delay(100);
  
}
