#include <Ultrasonic.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
Ultrasonic ultrasonic(9,8);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop(){
    kirimdata();
}

void kirimdata(){
  float t = dht.readTemperature();
  int h = ultrasonic.Ranging(CM);
  String datakirim = String(h) + "#" + String(t);
  delay(500);
  Serial.println(datakirim);
  }
