int Relay = 8;

void setup() { 
  Serial.begin(9600);  
  pinMode(Relay, OUTPUT);
}

void loop() {
  digitalWrite(Relay,LOW);
  Serial.println("LIGHT OFF");
  delay(10000);
  digitalWrite(Relay,HIGH);
  Serial.println("LIGHT ON");
  delay(5000);
}
