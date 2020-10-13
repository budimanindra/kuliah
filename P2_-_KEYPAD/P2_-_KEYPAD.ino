void setup() {
pinMode(0, OUTPUT);
pinMode(1, OUTPUT);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
}

void satu()
//seven segment common anoda
  {
   digitalWrite(0, 1); //G
   digitalWrite(1, 1); //F
   digitalWrite(2, 1); //E
   digitalWrite(3, 1); //D
   digitalWrite(4, 0); //C
   digitalWrite(5, 0); //B
   digitalWrite(6, 1); //A
    }

void tujuh()
//seven segment common katoda
  {
   digitalWrite(7, 0); //G
   digitalWrite(8, 0); //F
   digitalWrite(9, 0); //E
   digitalWrite(10, 0); //D
   digitalWrite(11, 1); //C
   digitalWrite(12, 1); //B
   digitalWrite(13, 1); //A
    }
 
void loop() {
satu();    
tujuh();    
}
