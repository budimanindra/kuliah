#include <Ultrasonic.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
Ultrasonic ultrasonic(9,8);

float temperature, pH;
int jarak;

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop(){
    kirimdata();
}

void kirimdata(){
  temperature = dht.readTemperature();
  jarak = ultrasonic.Ranging(CM);
  String datakirim = String(jarak) + "#" + String(temperature);
  Serial.println(datakirim);
  delay(15000);
  }
