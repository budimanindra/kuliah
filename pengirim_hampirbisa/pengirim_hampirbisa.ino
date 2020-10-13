#include <Ultrasonic.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
Ultrasonic ultrasonic(9,8);

float temperature, lembab, pH;
int jarak;

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop(){
  String minta = "";
  while(Serial.available()>0)
  {
    minta += char(Serial.read());
  }
  minta.trim();
  if(minta == "Meminta Data Dari Arduino...")
  {
    kirimdata();
  }

  //mengosongkan variabel minta dan waktu cek tiap sedetik
  minta = "";
  delay(1000);
}

void kirimdata(){
  temperature = dht.readTemperature();
  lembab = dht.readHumidity();
  jarak = ultrasonic.Ranging(CM);
  String datakirim = String(jarak) + "#" + String(temperature) + "#" + String(lembab);
  Serial.println(datakirim);
  }
