# stm32-ultrasonic-lcd
# STM32 Ultrasonic Sensor with LCD Display

This project demonstrates how to interface an **HC-SR04 ultrasonic distance sensor** with an **I2C LCD 16x2** display using a **STM32 Nucleo-F411RE** board.  
The measured distance is displayed in centimeters on the LCD.

---

## 🛠 Hardware
- STM32 Nucleo-F411RE
- HC-SR04 ultrasonic sensor
- I2C LCD 16x2 (PCF8574 backpack)
- Jumper wires

---

## 🔌 Wiring

### Ultrasonic Sensor
| HC-SR04 Pin | STM32 Pin |
|-------------|-----------|
| VCC         | 5V        |
| GND         | GND       |
| TRIG        | PA0       |
| ECHO        | PA1       |

### LCD I2C
| LCD Pin | STM32 Pin |
|---------|-----------|
| VCC     | 5V        |
| GND     | GND       |
| SDA     | PB9 (D14) |
| SCL     | PB8 (D15) |

---

## 💻 Software
- [PlatformIO](https://platformio.org/)
- Framework: Arduino Core STM32
- Libraries:
  - `LiquidCrystal_I2C`

---

## 🚀 How to Run
1. Clone this repository:
   ```bash
   git clone https://github.com/<your-username>/stm32-ultrasonic-lcd.git
