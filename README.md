# Tiva C GPIO Projects: LED and Switch Interface 

This repository contains a collection of beginner-to-intermediate level embedded C projects developed for the **Tiva C Series TM4C123GH6PM** microcontroller. These projects demonstrate the use of **GPIO pins** to control LEDs and read switches, providing a practical introduction to working with hardware interfaces on ARM Cortex-M4.

## Table of Contents

- [Overview](#overview)
- [Projects](#projects)
- [Requirements](#requirements)
- [How to Build and Run](#how-to-build-and-run)
- [License](#license)

---

## Overview

These examples use **Tiva C (TM4C123GH6PM)** microcontroller to:

- Blink LEDs in sequence
- Toggle LEDs with button presses
- Demonstrate debouncing and pull-up configurations
- Use bit-banding to control individual GPIO pins

All programs directly access memory-mapped registers to configure and control GPIO functionality.

---

## Projects

| Project # | Description |
|----------|-------------|
| 1 | Toggle Red LED using SW2 (PF0) |
| 2 | Switch SW1 (PF4) toggles Blue LED with debounce logic |
| 3 | Cycle through Red, Blue, and Green LEDs using SW1 and SW2 |
| 4 | Blink Red, Blue, and Green LEDs in sequence |
| 5 | Same as #4, using **bit-banding** to individually access pins |
| 6 | Same as #5, using a combined memory-mapped alias for PF1-PF3 |
| 7 | Read temperature using LM35 sensor and display it on an LCD (bonus: uses ADC and LCD modules) |

---

## Requirements

- **Tiva C LaunchPad (TM4C123GH6PM)**
- Code Composer Studio (CCS) or Keil µVision
- TivaWare drivers or custom register definitions (e.g., `tm4c123gh6pm_registers.h`)
- USB cable for programming the board
- (Optional) LM35 sensor and 16x2 LCD display for Project 7

---

## How to Build and Run

1. Open your preferred IDE (CCS, Keil, etc.)
2. Create a new project and select the TM4C123GH6PM device.
3. Add the required source files and `tm4c123gh6pm_registers.h`.
4. Copy-paste the code from one of the `.c` files.
5. Build the project and flash it to the board.
6. Observe the output via the onboard LEDs and switches.

---

## License

This project is provided for educational purposes and is released under the MIT License.

---

## Author

Eyad – Embedded Systems Enthusiast
