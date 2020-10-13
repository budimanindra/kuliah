#include <SoftwareSerial.h>

const int trigPin = 8;
const int echoPin = 9;

long duration;
int distance;

SoftwareSerial uno(3,2);

void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
uno.begin(9600);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance= duration*0.034/2;

Serial.print("Distance: ");
Serial.println(distance);

while (uno.available()>0){
delay(10);
int distance = uno.read();
}
if (distance.length()>0){
  Serial.println(distance);
  distance = "";
}
}
