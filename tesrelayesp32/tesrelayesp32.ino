#define BLYNK_PRINT Serial
int relay1 = 5;
int relay2 = 18;
int relay3 = 19;
int relay4 = 21;
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "gatsw9t-pzkuJ7yUpX8B_lXI4-8JRHWb";
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "jowy";
char pass[] = "indraindra";

void setup() {
pinMode(relay1, OUTPUT);
pinMode(relay2, OUTPUT);
pinMode(relay3, OUTPUT);
pinMode(relay4, OUTPUT);
pinMode(relay1, HIGH);
pinMode(relay2, HIGH);
pinMode(relay3, HIGH);
pinMode(relay4, HIGH);
Serial.begin(115200);
delay(10);
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, pass);
int wifi_ctr = 0;
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("WiFi connected");
Blynk.begin(auth, ssid, pass);
}
void loop(){
Blynk.run();
}
