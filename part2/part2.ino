#include <SoftwareSerial.h>

//tx,rx
SoftwareSerial DataSerial (12,13);

unsigned long previousMillis = 0;
const long interval = 3000;

String arrData[2];

void setup(){
  Serial.begin (115200);
  DataSerial.begin (115200);
}


void loop(){
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    String data = "";
    while (DataSerial.available()>0)
    {
      data += char (DataSerial.read());
    }
    data.trim ();
    if(data != "")
    {
      int index = 0;
      for (int i=0; i<= data.length(); i++)
      {
        char delimiter = '#';
        if (data[i] != delimiter)
          arrData [index] += data[i];
        else
        index ++;
      }

      //cek data yg dikirim lengkap (jarak, temperatur)
      if(index == 1)
      {
        Serial.println(arrData[0]);
        Serial.println(arrData[1]);
      }
      arrData[0] = "";
      arrData[1] = "";
    }
    //minta data ke arduino UNO
    DataSerial.println("Ya");
  }
}
