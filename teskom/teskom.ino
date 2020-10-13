#include<SoftwareSerial.h>
int a;
SoftwareSerial komunikasi(3,2);

void setup() {
 Serial.begin(9600);
 komunikasi.begin(9600);
}

void loop() {
komunikasi.available();
a = komunikasi.read();
Serial.print("Jarak terbaca: ");
Serial.println(a);
delay (1000);

}
