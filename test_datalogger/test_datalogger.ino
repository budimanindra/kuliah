#include <SD.h>
#include <SPI.h>
#include <DS3231.h>
#include <Ultrasonic.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
File myFile;
DS3231  rtc(SDA, SCL);
Ultrasonic ultrasonic(9,8); // (Trig PIN,Echo PIN)
int pinCS = 10;
void setup() {
    
  Serial.begin(9600);
  pinMode(pinCS, OUTPUT);
  
  // SD Card Initialization
  if (SD.begin())
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
    return;
  }
  dht.begin();
  rtc.begin();    
}
void loop() {
  Serial.print(rtc.getDOWStr());
  Serial.print(",");
  Serial.print(rtc.getDateStr());
  Serial.print(",");
  Serial.print(rtc.getTimeStr());
  Serial.print(",");
  float t = dht.readTemperature();
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(",");
  Serial.println(ultrasonic.Ranging(CM)); // CM or INC
 
  myFile = SD.open("LOGGER.txt", FILE_WRITE);
  if (myFile) {    
    myFile.print(rtc.getDOWStr());
    myFile.print(",");
    myFile.print(rtc.getDateStr());
    myFile.print(",");
    myFile.print(rtc.getTimeStr());
    myFile.print(",");    
    myFile.print(F("Temperature: "));
    myFile.print(t);
    myFile.print(F("°C "));
    myFile.print(",");
    myFile.print(ultrasonic.Ranging(CM)); // CM or INC
    myFile.close(); // close the file
  }
  // if the file didn't open, print an error:
  else {
    Serial.println("error opening LOGGER.txt");
  }
  delay(3000);
}
