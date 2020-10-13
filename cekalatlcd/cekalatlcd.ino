#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LCD.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

void setup() 
{ 
Serial.begin(9600);
lcd.begin(16,2);
lcd.backlight();  
}

void loop() 
{
lcd.setCursor(0, 0);
lcd.print("INDRA");
lcd.setCursor(0, 1);
lcd.print("BUDIMAN");
}
