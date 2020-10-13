#include <Wire.h>
float teg[10];
double tds, konduktifitas;
float rata_rata_teg;
void setup() {
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
for ( int i=0; i<10; i++){
int val = analogRead(A0);
teg[i] = val * (5.0/1023);
}
rata_rata_teg = (teg[0] + teg[1] + teg[2] + teg[3] + teg[4] + teg[5] + teg[6] + teg[7] + teg[8] + teg[9])/10 ;
delay(1000);
tds = (211.2254 * rata_rata_teg) - 144.1466;
konduktifitas = (0.3442 * rata_rata_teg) - 0.253;
Serial.print(rata_rata_teg);
Serial.print("  conductivity (uSiemens)= ");
Serial.println(tds);
Serial.print("  TDS(ppm)= ");
Serial.println(konduktifitas);
delay(1000);
}
