#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LCD.h>
#include <DHT.h>

#define DHTPIN 2

#define DHTTYPE DHT22

const int buzzer = 7;
const int led = 13;


LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
 
Serial.begin(9600);
lcd.begin(16,2);
lcd.backlight();
pinMode(led, OUTPUT);
lcd.print("INDRA F1B016036");
dht.begin();
}

void loop(){
delay(2000);
noTone(buzzer);
digitalWrite (led,LOW);
int h = dht.readHumidity();
int t = dht.readTemperature();

lcd.setCursor(0,1);
lcd.print(" H:");
lcd.print(h);
lcd.print(" --- ");
lcd.print("T:");
lcd.print(t);
lcd.print("C");

Serial.print("H: ");
Serial.println(h);
Serial.print("T: ");
Serial.print(t);
Serial.println("*C");
  
  if (h > 75.00){
    Serial.println ("ALARM ON");
    tone(buzzer, 700);
    digitalWrite (led,HIGH);
  }
}
