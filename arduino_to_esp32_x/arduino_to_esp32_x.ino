void setup() {
  Serial.begin(9600);
}

void loop() {
  int TDS = analogRead(0);
  Serial.println(TDS);
  delay(1000);
}
