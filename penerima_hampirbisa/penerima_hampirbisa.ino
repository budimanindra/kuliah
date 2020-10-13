#include "ThingSpeak.h"
#include <WiFi.h>

String arrData[3];

int Jarak;
float Suhu, Lembab;

const char *ssid = "jowy";   // your network SSID (name) 
const char *password = "indraindra";   // your network password
const char* server = "api.thingspeak.com";

unsigned long channel = 1105207; //your channel ID number
const char *apiKey = "5EUTXZ4IALZPUA0U"; //your channel write API Key

WiFiClient client;

void setup(){
  Serial.begin(115200);
  delay(10);
  
    Serial.print("Connecting to: ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nWiFi connected\n");
  ThingSpeak.begin(client); //initialize ThingSpeak
}

void loop(){
  String data = "";
  Serial.println("Meminta Data Dari Arduino...");    
  while (Serial.available()>0)
  {
    data += char (Serial.read());
  }
  data.trim();
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
      if(index == 2)
      {
        Serial.println("Berhasil menerima data dari Arduino");
        Jarak = arrData[0].toInt();
        Suhu  = arrData[1].toFloat();
        Lembab  = arrData[2].toFloat();
        ThingSpeak.setField(1, Jarak);
        ThingSpeak.setField(2, Suhu);
        ThingSpeak.setField(3, Lembab);
        int x = ThingSpeak.writeFields(channel, apiKey);
        if (x == 200) {
          Serial.println("Jarak       : " + arrData[0]);
          Serial.println("Suhu        : " + arrData[1]);
          Serial.println("Kelembaban  : " + arrData[2]);
          Serial.println("Berhasil mengupdate data ke ThingSpeak.");
        }
        else {
          Serial.println("Gagal mengupdate data ke Thingspeak. Error code " + String(x));
        }
      }
      arrData[0] = "";
      arrData[1] = "";
      arrData[2] = "";
    }
  delay(15000);
}
