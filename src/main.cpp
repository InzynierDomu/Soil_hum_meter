/**
 * @file main.cpp
 * @author by Szymon Markiewicz (https://github.com/InzynierDomu/)
 * @brief Soil humidity meter
 * @date 2023-07
 */

#include "LiquidCrystal_I2C.h"

#include <Arduino.h>
#include <Wire.h>

const int lcdAddr = 0x27;
LiquidCrystal_I2C lcd(lcdAddr, 16, 2);

const int analogPin = A3;

void setup()
{
  Wire.begin();

  lcd.begin(16, 2);
  lcd.backlight();

  lcd.print("Soil hum: ");
}

void loop()
{
  int sensorValue = analogRead(analogPin);

  int percentage = map(sensorValue, 0, 1023, 0, 100);

  lcd.setCursor(0, 1);
  lcd.print(percentage);
  lcd.print("%");

  delay(500);
}
