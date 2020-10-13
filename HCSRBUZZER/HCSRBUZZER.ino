#include <Ultrasonic.h>
const int pinBuzzerl = 4;
const int pinBuzzerr = 3;


Ultrasonic ultraleft(5, 6);  // (Trig PIN,Echo PIN)
Ultrasonic ultraright(8, 7);  // (Trig PIN,Echo PIN)

void setup() {
  pinMode(pinBuzzerl, OUTPUT);
  pinMode(pinBuzzerr, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Left: ");
  Serial.print(ultraleft.Ranging(CM)); // CM or INC
  Serial.println(" cm     " );
  Serial.print("Right: ");
  Serial.print(ultraright.Ranging(CM)); // CM or INC
  Serial.println(" cm     " );
  delay(50);
  if (ultraleft.Ranging(CM) < 10) {
    digitalWrite(pinBuzzerl, HIGH);    //buzzer bunyi dengan delay
    delay(50);
  }
  else (ultraleft.Ranging(CM) > 10);
  digitalWrite(pinBuzzerl, LOW);     //buzzer mati dengan delay
  if (ultraright.Ranging(CM) < 10) {
    digitalWrite(pinBuzzerr, HIGH);    //buzzer bunyi dengan delay
    delay(50);
  }
  else (ultraright.Ranging(CM) > 10);
  digitalWrite(pinBuzzerr, LOW);     //buzzer mati dengan delay
}
