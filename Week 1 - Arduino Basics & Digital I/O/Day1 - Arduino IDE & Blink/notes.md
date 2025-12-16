# Day 1 - Arduino IDE & Blink

## Goal
- Learn to use Arduino IDE
- Blink an onboard LED
- Understand digital output and timing

## Hands-on Exercise
1. Upload the `code.ino` to Arduino UNO.
2. Observe the onboard LED blinking.
3. Change blink speed by adjusting `delay()`.
4. Connect an external LED on pin 8 and blink it.

## Concepts / Notes
- `pinMode(pin, OUTPUT)` → sets the pin as output
- `digitalWrite(pin, HIGH/LOW)` → turns the pin on/off
- `delay(ms)` → pauses the program for given milliseconds
- Arduino sketches have **setup()** (runs once) and **loop()** (runs repeatedly)
