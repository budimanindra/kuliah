#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "MXCs_6p999Oe3O218PCyhVKXF7A0h7MJ";
char ssid[] = "jowy";
char pass[] = "indraindra";

String arrData[4];

int jarak, total_volume1, total_volume2, total_volume3;

void setup() {
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
}
void loop() {
  String data = "";
  Serial.println("Meminta Data Dari Arduino...");
  while (Serial.available() > 0)
  {
    data += char (Serial.read());
  }
  data.trim();
  if (data != "")
  {
    int index = 0;
    for (int i = 0; i <= data.length(); i++)
    {
      char delimiter = '#';
      if (data[i] != delimiter)
        arrData [index] += data[i];
      else
        index ++;
    }

    if (index == 3)
    {
      Blynk.run();
      Serial.println("Berhasil menerima data dari Arduino");
      jarak             = arrData[0].toInt();
      total_volume1     = arrData[1].toInt();
      total_volume2     = arrData[2].toInt();
      total_volume3     = arrData[3].toInt();
      Serial.println("jarak     :" + arrData[0]);
      Serial.println("volume 1  :" + arrData[1]);
      Serial.println("volume 2  :" + arrData[2]);
      Serial.println("volume 3  :" + arrData[3]);
      Blynk.virtualWrite(V0, jarak);
      Blynk.virtualWrite(V1, total_volume1);
      Blynk.virtualWrite(V2, total_volume2);
      Blynk.virtualWrite(V3, total_volume3);
      delay(100);
    }
    arrData[0] = "";
    arrData[1] = "";
    arrData[2] = "";
    arrData[3] = "";
  }
  delay(5000);
}
