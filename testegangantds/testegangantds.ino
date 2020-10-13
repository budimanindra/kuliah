float teg[10];
double tds;
float rata_rata_teg;
void setup() {
Serial.begin(9600);
}
void loop() {
for ( int i=0; i<10; i++){
int val = analogRead(A0);
teg[i] = val * (5.0/1023);
}
rata_rata_teg = (teg[0] + teg[1] + teg[2] + teg[3] + teg[4] + teg[5] + teg[6] + teg[7] + teg[8] + teg[9])/10 ;
delay(1000);
tds = (406.8965517 * rata_rata_teg) - 131.7241379;
Serial.print("Rata-rata tegangan ");
Serial.println(rata_rata_teg);
Serial.print("Nilai TDS ");
Serial.println(tds);
delay(1000);
}
