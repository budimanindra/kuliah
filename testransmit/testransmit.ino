//transmitter
#include <SoftwareSerial.h>

SoftwareSerial serial(2,3);

void setup() {
  // put your setup code here, to run once:
serial.begin(9600);
serial.print("jowy");
}

void loop() {
  // put your main code here, to run repeatedly:

}
