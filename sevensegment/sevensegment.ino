void setup() {

pinMode(0, OUTPUT);
pinMode(1, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
}

void sembilan()
  {
   digitalWrite(0, 0); //G
   digitalWrite(1, 0); //F
   digitalWrite(2, 1); //E
   digitalWrite(3, 0); //D
   digitalWrite(4, 0); //C
   digitalWrite(5, 0); //B
   digitalWrite(6, 0); //A
    }
    
void loop() {
sembilan();    
delay(1000);
}

