const int pinBuzzer = 7;

void setup() {
  pinMode(pinBuzzer, OUTPUT);
}

void loop() {
  digitalWrite(pinBuzzer, HIGH);    //buzzer bunyi dengan delay
  delay(200);                       //delay 200 milisecond
  digitalWrite(pinBuzzer, LOW);     //buzzer mati dengan delay
  delay(200);                       //delay 200 milisecond
  digitalWrite(pinBuzzer, HIGH);    //buzzer bunyi dengan delay
  delay(200);                       //delay 200 milisecond
  digitalWrite(pinBuzzer, LOW);     //buzzer mati dengan delay
  delay(1000);                      //delay 1000 milisecond
}
