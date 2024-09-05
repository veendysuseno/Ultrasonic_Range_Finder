# Ultrasonic Range Finder

## Description

This project demonstrates how to measure distance using an ultrasonic sensor and display the results on an LCD screen. The ultrasonic sensor sends out a pulse and measures the time it takes for the echo to return. The distance is then calculated and shown on the LCD.

## Components

- Arduino (e.g., Arduino Uno)
- Ultrasonic Sensor (e.g., HC-SR04)
- 16x2 LCD with I2C Interface
- Jumper wires
- Breadboard (optional)

## Pin Configuration

| Component   | Pin Number                          |
| ----------- | ----------------------------------- |
| Echo Pin    | 10                                  |
| Trigger Pin | 11                                  |
| LCD SDA     | A4 (or as specified for your board) |
| LCD SCL     | A5 (or as specified for your board) |

## Libraries Required

- **Wire**: For I2C communication.
- **LiquidCrystal_I2C**: For controlling the LCD. Install this library via the Arduino Library Manager.

## Code

```cpp
// Code Ultrasonic Range Finder
#define ECHOPIN 10
#define TRIGPIN 11

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
  lcd.begin();
  lcd.backlight();
  lcd.print("Range Finder");
  lcd.setCursor(0, 1);
  lcd.print("Range=");

  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  delay(1000);
}

void loop(){
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  int distance = pulseIn(ECHOPIN, HIGH);
  distance = distance / 58;

  lcd.setCursor(6, 1);
  lcd.print(distance);
  lcd.print(" cm ");
  delay(1000);
}
```

## How It Works

1. Initialization: The setup() function initializes the LCD and sets the pins for the ultrasonic sensor.
2. Distance Measurement:
   - The loop() function sends a pulse from the TRIG pin and measures the duration of the echo received on the ECHO pin.
   - The duration is then converted into distance (in centimeters) and displayed on the LCD.

## Usage

1. Connect the ultrasonic sensor and LCD to the specified pins on the Arduino.
2. Upload the code to your Arduino board.
   3.Observe the distance measurements displayed on the LCD.

## Notes

- Ensure the LCD's I2C address (0x27 in the code) matches your hardware. If not, you may need to scan for the correct address using an I2C scanner sketch.
- Adjust the delay(1000) in the loop() function to change the update rate of the distance display.
