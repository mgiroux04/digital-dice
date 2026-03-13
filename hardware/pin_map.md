# Pin Map — TM4C123GH6PM Digital Dice

## GPIO Port F — LED Outputs

| Pin | Color Channel |
|-----|--------------|
| PF1 | Red          | 
| PF2 | Blue         |
| PF3 | Green        |

---

## Roll-to-LED Mapping

| Roll | Color   | PF1 (Red) | PF2 (Blue) | PF3 (Green) | GPIO_PORTF_DATA (hex) |
|------|---------|-----------|------------|-------------|-----------------------|
| 1    | Red     | 1         | 0          | 0           | 0x02                  |
| 2    | Blue    | 0         | 1          | 0           | 0x04                  |
| 3    | Magenta | 1         | 1          | 0           | 0x06                  |
| 4    | Green   | 0         | 0          | 1           | 0x08                  |
| 5    | Yellow  | 1         | 0          | 1           | 0x0A                  |
| 6    | Cyan    | 0         | 1          | 1           | 0x0C                  |

> Off state: all pins LOW → 0x00

> NOTE: d4 and d6 have the same outputs for numbers 1-4

---

