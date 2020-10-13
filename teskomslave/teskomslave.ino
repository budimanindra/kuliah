#include<SoftwareSerial.h>
SoftwareSerial komunikasi(2, 3);

const int trigPin = 8;
const int echoPin = 9;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  scan();
  if (komunikasi.available() > 0) {
    komunikasi.write(distance);
  }
}

void scan() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
  delay (300);
}
