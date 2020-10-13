#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

}

void loop() {

  float t = dht.readTemperature();
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));

  delay (5000);
}
