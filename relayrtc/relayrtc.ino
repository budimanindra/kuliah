#include <SD.h>
#include <SPI.h>
#include <DS3231.h>
#include <Ultrasonic.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
DS3231  rtc(SDA, SCL);
Time t;
Ultrasonic ultrasonic(9,8); // (Trig PIN,Echo PIN)

int Relay = 4;
const int OnHour = 21;
const int OnMin = 35;
const int OffHour = 21;
const int OffMin = 40;


void setup() {
    
  Serial.begin(9600);  
  dht.begin();
  rtc.begin();    
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, LOW);
}

void loop() {
  t = rtc.getTime();
  Serial.print(t.hour);
  Serial.print(" hour(s), ");
  Serial.print(t.min);
  Serial.print(" minute(s)");
  Serial.println(" ");
  float h = dht.readTemperature();
  Serial.print(F("Temperature: "));
  Serial.print(h);
  Serial.print(F("°C "));
  Serial.print(",");
  Serial.println(ultrasonic.Ranging(CM)); // CM or INC

  if(t.hour == OnHour && t.min == OnMin){
    digitalWrite(Relay,HIGH);
    Serial.println("LIGHT ON");
    }
    
    else if(t.hour == OffHour && t.min == OffMin){
      digitalWrite(Relay,LOW);
      Serial.println("LIGHT OFF");
    }

   delay(5000);
}
