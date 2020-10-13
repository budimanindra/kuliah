#include <DS3231.h>
#include "DHT.h"
#include <Ultrasonic.h>
#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
Ultrasonic ultrasonic(9,8); // (Trig PIN,Echo PIN)
DS3231  rtc(SDA, SCL);

void setup() {
  Serial.begin(9600);
  dht.begin();
  rtc.begin();

}

void loop() {
    // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // Send time
  Serial.println(rtc.getTimeStr());
 
  float t = dht.readTemperature();

  if (isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
  
  Serial.print(ultrasonic.Ranging(CM)); // CM or INC
  Serial.println("cm");
  Serial.println(" ");

  delay (5000);
}
