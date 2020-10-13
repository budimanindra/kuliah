#include <Ultrasonic.h>

Ultrasonic ultrasonic(9,8); // (Trig PIN,Echo PIN)

void setup() {
  Serial.begin(9600); 
}

void loop()
{
  Serial.println(ultrasonic.Ranging(CM));
  delay(500);
}
