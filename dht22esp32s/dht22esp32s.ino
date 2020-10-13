#include "DHTesp.h"
#define DHTPIN 27
DHTesp dht;

void setup(){
Serial.begin(115200);
}

void loop(){
float temperature = dht.getTemperature();

Serial.print("Temperature: ");
Serial.println(temperature);

delay(10000);
}
