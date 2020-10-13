#include <SoftwareSerial.h>

SoftwareSerial DataSerial (12,13);

unsigned long previousMillis = 0;
const long interval = 3000;

String arrData[2];

void setup() {
  Serial.begin(115200);
  DataSerial.begin(115200);
}

void loop() {
  //konfigrasi millis
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    String sarip = "";
    while(DataSerial.available()>0)
    {
      sarip += char(DataSerial.read());
    }
    sarip.trim();

    if(sarip != "")
    {
      int index = 0;
      for(int i=0; i<= sarip.length(); i++)
      {
        char delimiter = '#';
        if(sarip[i] != delimiter)
            arrData[index] += sarip[i];
        else
            index++;
      }

      //cek data yang dikirim lengkap
      if (index == 1){
        Serial.println ("Ketinggian air : " + arrData[0]);
        Serial.println ("Suhu           : " + arrData[1]);
      }
            
      arrData [0] = "";
      arrData [1] = "";

    }
    DataSerial.println("Ya");
  }
}
