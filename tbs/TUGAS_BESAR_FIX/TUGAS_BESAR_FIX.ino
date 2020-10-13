#include <Servo.h>
const byte pinBuzzer = 2;
const int EPin = 12;
const int TPin = 11;
int yellowPin = 5;
int greenPin = 6;
long jarak;
int durasi;
Servo myservo;   
int pos = 0;

void setup() {
pinMode(pinBuzzer, OUTPUT);
myservo.attach(9);
pinMode(EPin,INPUT);
pinMode(TPin,OUTPUT);
Serial.begin(9600);
pinMode(yellowPin, OUTPUT);
pinMode(greenPin, OUTPUT);

}

void loop() {
digitalWrite(TPin,HIGH);
delayMicroseconds(10);
digitalWrite(TPin,LOW);

durasi = pulseIn(EPin,HIGH);
jarak = durasi/58;
Serial.print(jarak);
Serial.print("cm");
Serial.println();
delay (1000);

if (jarak <=4){
  myservo.write(165);
    digitalWrite(yellowPin, LOW);  
digitalWrite(greenPin, HIGH);
digitalWrite(pinBuzzer, HIGH);
delay(200);
digitalWrite(pinBuzzer, LOW);
delay(200);
digitalWrite(pinBuzzer, HIGH);
delay(200);
digitalWrite(pinBuzzer, LOW);
delay(200);
digitalWrite(pinBuzzer, HIGH);
delay(200);
digitalWrite(pinBuzzer, LOW);
delay(200);
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);
    myservo.write(65);

  }
  else{
    myservo.write(65);
        digitalWrite(yellowPin, HIGH);
        digitalWrite(pinBuzzer, LOW);
    delay(5);
  }
}
