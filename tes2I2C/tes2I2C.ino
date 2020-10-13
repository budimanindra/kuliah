#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LCD.h>
#include <DS3231.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

DS3231  rtc(SDA, SCL);
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

void setup() 
{ 
Serial.begin(9600);
dht.begin();
rtc.begin();
lcd.begin(16,2);
lcd.backlight();
}

void loop() 
{
  Serial.print(rtc.getDateStr());
  Serial.print(",");
  Serial.print(rtc.getTimeStr());
  Serial.println(",");
  lcd.setCursor(0, 0);
  lcd.print(rtc.getTimeStr());
  float t = dht.readTemperature();
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(",");
  lcd.setCursor(0, 1);
  lcd.print(F("T: "));
  lcd.print(t);
  lcd.print(F("C"));
  lcd.setCursor(10,1);
  lcd.print("INDRA");
  delay(1000);
  }
