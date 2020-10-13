#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
 
BLYNK_WRITE (V2); 
String data;
String I;

char auth[] = "MXCs_6p999Oe3O218PCyhVKXF7A0h7MJ";
char ssid[] = "JTE 5";
char pass[] = "hujansenja";
 
BlynkTimer timer;
String myString; 
char rdata; 

void myTimerEvent()
{
  Blynk.virtualWrite(V1, millis() / 1000);
}
void setup()
{
  // Debug console
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, sensorvalue1);       
}
void loop()
{
 
   if (Serial.available() == 0 ) 
   {
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
   }
   
  if (Serial.available() > 0 ) 
  {
    rdata = Serial.read(); 
    myString = myString+ rdata; 
    Serial.print(rdata);
    if( rdata == '\n')
    {
      int I = myString.toInt() ;
      myString = "";
      Serial.println(I);
      Blynk.virtualWrite(V2, I); 
    }
  }
 
}
   
void sensorvalue1()
{
  data = data + I;
  Serial.println(data);
  Blynk.virtualWrite(V2 ,data); 
  data = "";
}
 
String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;
 
    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

