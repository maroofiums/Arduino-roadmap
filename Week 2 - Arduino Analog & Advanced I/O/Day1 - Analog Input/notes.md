# Week 2 — Day 1: Analog Concept (Without Potentiometer)

## Goal

* Understand **analog control** concept without a potentiometer
* Learn **PWM (Pulse Width Modulation)**
* Control LED brightness using **button + software logic**

---

## Key Concepts

### 1. Digital vs Analog

* **Digital**: Only two states → `0 / 1`, `LOW / HIGH`
* **Analog**: Range of values → smooth control (0% → 100%)

Examples:

* Button → Digital
* LED brightness / motor speed → Analog (via PWM)

---

### 2. PWM (Pulse Width Modulation)

Arduino UNO does **not** generate real analog voltage.
Instead, it uses PWM:

* Rapid ON/OFF switching
* Different ON time → different brightness

PWM value range:

* `0`   → LED OFF
* `255` → LED FULL BRIGHT

PWM Pins on Arduino UNO:

```
~3, ~5, ~6, ~9, ~10, ~11
```

---

### 3. Why No Potentiometer?

* Hardware not available
* Real-world situation
* Use **button + logic** to simulate analog behavior

This teaches:

* Control logic
* State handling
* Embedded system thinking

---

## Hardware Connections

### LED

* Long leg (+) → **Pin 9 (PWM)**
* Short leg (−) → **220Ω resistor → GND**

### Button

* One side → **Pin 2**
* Other side → **GND**

Arduino internal pull-up resistor is used (no external resistor needed).

---

## Code Logic (High-Level)

```
Button Pressed
      ↓
Increase Brightness (step-wise)
      ↓
Apply PWM to LED
      ↓
If brightness > 255 → reset to 0
```

---

## Important Code Concepts

### INPUT_PULLUP

* Button released → HIGH
* Button pressed → LOW
* Stable input without extra hardware

### Brightness Variable

* Stores LED intensity
* Incremented manually to simulate analog input

### Debounce Delay

* Small delay avoids multiple false triggers
* Makes button control smooth

---

## What You Learned Today

* Analog control can be **simulated in software**
* PWM is the backbone of brightness & speed control
* Hardware limitation does not stop learning

---

## Common Mistakes to Avoid

* Using non-PWM pin for LED
* Forgetting resistor with LED
* Not handling button debounce

---
