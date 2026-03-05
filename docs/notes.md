# Dev Notes — TM4C123GH6PM Digital Dice

## Development Environment
- **MCU**: TM4C123GH6PM (Tiva C Series LaunchPad)
- **IDE**: Keil MDK
- **Language**: C

---

## Current State (v0.1 — Proof of Concept)
- Button press triggers a random number generation (1–6)
- Result is displayed via RGB LED color on Port F
- 3 GPIO pins (PF1, PF2, PF3) drive 6 unique colors through combinations


---

## Known Limitations
- RNG may not be truly random (seeding may need improvement) 
- No roll animation (LED snaps immediately to result)
- Result is displayed exclusively during the duration of the button press.
---

## Future Ideas

### Short Term
- [ ] Add debounce handling on the button input
- [ ] Improve RNG with a better entropy source 

### Medium Term
- [ ] Support multiple dice types: d4, d8, d10, d12, d20
- [ ] Mode button to switch between dice types
- [ ] Display result on LED Display
