# 🎲 Digital Dice — TM4C123GH6PM

A hardware proof-of-concept for a digital d6 built on the TM4C123GH6PM microcontroller. Press a button, get a random roll — displayed instantly via onboard LEDs.

---

## What It Does

- Press a button to "roll" the die
- A random number from 1–6 is generated
- The corresponding LED lights up to display the result

---

## Hardware

| Component | Details |
|---|---|
| Microcontroller | TM4C123GH6PM (Tiva C Series) |
| LEDs | 6 of 7 onboard GPIO-driven LED outputs used |
| Input | Onboard push button |

---

## Project Structure

```
/src          → C source code (main logic, RNG, LED mapping)
/hardware     → Wiring diagrams, pin mappings
/docs         → Notes, references, datasheets
README.md     → You're here
```

---

## Getting Started

1. Clone this repo
2. Open in Code Composer Studio (or your preferred TM4C IDE)
3. Flash to your TM4C123GH6PM board
4. Press the button — watch an LED light up

> ⚠️ This is a proof of concept. Expect rough edges.

---

## Roadmap

- [ ] Add roll animation (LEDs cycle before settling)
- [ ] Improve randomness with entropy seeding
- [ ] Support additional dice (d4, d8, d10, d12, d20)
- [ ] Shake-to-roll via accelerometer (MPU-6050)
- [ ] Buzzer feedback on roll
- [ ] Custom PCB + 3D-printed enclosure
- [ ] Low-power sleep/wake mode

---

## Why I Built This

This started as a hardware proof of concept and is growing into a full dice suite project. It's part of my ongoing work building embedded systems projects from scratch — from prototype to polished hardware product.

---

## Author

**Mike Giroux**  
[GitHub Profile] · [LinkedIn] · [Portfolio/Website]
