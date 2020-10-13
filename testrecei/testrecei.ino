//reciver
#include <SoftwareSerial.h>

SoftwareSerial serial(3,2);

String data;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
while (serial.available()>0){
  delay(10);
  char c = serial.read();
data+=c;

}if (data.length()>0){
  Serial.println(data);
  data="";
}
}
