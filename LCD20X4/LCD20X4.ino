#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LCD.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

void setup() { 
  lcd.begin(20,4);
  lcd.backlight();
  }

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("  Hidroponik Indoor");
  lcd.setCursor(0, 1);
  lcd.print("    Berbasis IoT");
  lcd.setCursor(0, 2);
  lcd.print("   INDRA BUDIMAN");
  lcd.setCursor(0, 3);
  lcd.print("     F1B016036");
  delay (10000);
  }
