#include "ThingSpeak.h"
#include <WiFi.h>

String arrData[2];

int Jarak;
float Suhu;

const char *ssid = "JTE 5";   // your network SSID (name) 
const char *password = "hujansenja";   // your network password
const char* server = "api.thingspeak.com";

unsigned long channel = 1054024; //your channel ID number
String apiKey = "979VWNXK6QURSSFE"; //your channel write API Key

WiFiClient client;

void setup(){
  Serial.begin(115200);
  delay(10);
  
  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop(){
  
  String data = "";
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
      if(index == 1)
      {
        Jarak = arrData[0].toInt();
        Suhu  = arrData[1].toFloat();
        Serial.println("Semua Data Berhasil Diterima");
        if (client.connect(server, 80))  //   "184.106.153.149" or api.thingspeak.com
  {

    String postStr = apiKey;
    postStr += "&field1=";
    postStr += String(Jarak);
    postStr += "&field2=";
    postStr += String(Suhu);
    postStr += "\r\n\r\n";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);

    Serial.print("Jarak : ");
    Serial.print(Jarak);
    Serial.print("Suhu  : ");
    Serial.print(Suhu);
    Serial.println("%. Send to Thingspeak.");
  }
   client.stop();
     Serial.println("Waiting...");

  // thingspeak needs minimum 15 sec delay between updates
  delay(15000);
      }
      arrData[0] = "";
      arrData[1] = "";
    }
}
