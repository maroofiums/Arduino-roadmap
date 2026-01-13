# Mini IoT Project

---

## **Step 1: Components You’ll Use**

* ESP32 or Arduino
* DHT11 sensor
* Ultrasonic sensor (HC-SR04)
* 3 LEDs (Green, Yellow, Red)
* Resistors (220Ω for LEDs)
* Jumper wires & breadboard

---

## **Step 2: Wiring**

### **DHT11**

* VCC → 3.3V (ESP32)
* GND → GND
* Data → GPIO 15 (you can choose another pin)

### **Ultrasonic (HC-SR04)**

* VCC → 5V
* GND → GND
* Trig → GPIO 2
* Echo → GPIO 4

### **LEDs**

* Connect LEDs with **220Ω resistors** to GPIO pins:

  * Green → GPIO 12
  * Yellow → GPIO 13
  * Red → GPIO 14
* Cathode → GND

> Tip: Use a breadboard so you can adjust pins easily.

---

## **Step 3: Logic Flow**

1. **Read DHT11** → Get temperature & humidity
2. **Set LED for temp/humidity comfort**

   * Temp < 25°C → Green
   * Temp 25–30°C → Yellow
   * Temp > 30°C → Red
3. **Read Ultrasonic sensor** → Distance from object
4. **If distance < 50 cm → Proximity LED ON**
5. **Combine conditions (optional)** → Flash LED if temp high AND someone is near

---

## **Step 4: Sample Code (ESP32 / Arduino)**

```cpp
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
```

---

## **Step 5: Optional Upgrade**

* Add **WiFi + Web Dashboard**: ESP32 sends temp/humidity + distance to a simple webpage.
* Use **FastAPI or Streamlit** to visualize in real-time.
* Can later **trigger notifications** if temp > 30°C or proximity < 50cm.
