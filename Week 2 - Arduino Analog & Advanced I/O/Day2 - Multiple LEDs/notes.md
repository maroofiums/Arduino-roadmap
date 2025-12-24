

# 🗓️ Week 2 — Day 2

## **Multiple LEDs & Traffic Light Logic**

### 🎯 Goal

* Multiple LEDs ko control karna
* Sequence / pattern banana
* `for` loop + timing ka real use
* Sochna: **state → next state**

---

## 🧠 Concept First (Engineer Thinking)

Real world examples:

* Traffic lights 🚦
* Lift indicators
* Server status LEDs
* Machine panels

👉 Ek LED akeli nahi hoti
👉 **Group mein behavior define hota hai**

---

## 🔧 Hardware Required

* Arduino UNO
* 3 LEDs (Red, Yellow, Green)
* 3 × 220Ω resistors
* Breadboard
* Jumper wires

---

## 🔌 Hardware Connections (Very Important)

### LEDs:

| LED Color | Arduino Pin |
| --------- | ----------- |
| Red       | 8           |
| Yellow    | 9           |
| Green     | 10          |

**Each LED:**

* Long leg (+) → Arduino pin
* Short leg (−) → **220Ω resistor → GND**

⚠️ Sab LEDs ke **GND common** ho sakte hain

---

## 💻 Code — Traffic Light System

```cpp
#define RED 8
#define YELLOW 9
#define GREEN 10

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {

  // 🔴 RED ON
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  delay(3000);

  // 🟡 YELLOW ON
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);
  delay(1000);

  // 🟢 GREEN ON
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);
  delay(3000);
}
```

---

## 🧩 Code Deep Explanation (Step-by-Step)

---

### 1️⃣ `#define` Pins

```cpp
#define RED 8
```

Why?

* Readable code
* Easy changes
* Compile-time (RAM safe)

Professional habit ✔️

---

### 2️⃣ `pinMode()`

```cpp
pinMode(RED, OUTPUT);
```

Arduino ko batate hain:

> “Ye pin signal bhejegi, sunegi nahi”

---

### 3️⃣ LED Control Logic

```cpp
digitalWrite(RED, HIGH);
digitalWrite(GREEN, LOW);
```

Traffic light rule:

* Ek time pe **sirf ek LED ON**

Ye **state-based logic** hai
(State = RED / YELLOW / GREEN)

---

### 4️⃣ `delay()` ka role

```cpp
delay(3000);
```

* RED & GREEN → long delay
* YELLOW → short delay

Real traffic jaise behavior 👍
