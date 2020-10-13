#include <NewPing.h>
#include <Servo.h>
#define TRIGGER_PIN   11
#define ECHO_PIN      12
#define MAX_DISTANCE 200



Servo servoAne;
NewPing ultrasonic1(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {

  Serial.begin(9600);
  servoAne.attach(9);
  servoAne.write(0);
}

void loop() {
  delay(50);
  int US1 = ultrasonic1.ping_cm();
  Serial.print("Hasil Sensor 1 :");
  Serial.print(US1);
  
  if(US1 <= 5){
    servoAne.write(180);
    delay(3000);
    servoAne.write(0);

  }
  else{
    servoAne.write(0);
    delay(5);
  }
}
