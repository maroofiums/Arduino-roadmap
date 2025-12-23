#define ledPin 9
#define buttonPin 2

int brightness = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {   // button pressed
    brightness += 50;

    if (brightness > 255) {
      brightness = 0;
    }

    analogWrite(ledPin, brightness);

    Serial.print("Brightness: ");
    Serial.println(brightness);

    delay(300);  // debounce + slow change
  }
}
