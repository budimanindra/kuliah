void setup() {
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
}

void nol()
  {
   digitalWrite(2, 1); //C
   digitalWrite(3, 1); //D 
   digitalWrite(4, 1); //E
   digitalWrite(5, 0); //G
   digitalWrite(6, 1); //F
   digitalWrite(7, 1); //A
   digitalWrite(8, 1); //B     
    }

void satu()
  {
   digitalWrite(2, 1); //C
   digitalWrite(3, 0); //D 
   digitalWrite(4, 0); //E
   digitalWrite(5, 0); //G
   digitalWrite(6, 0); //F
   digitalWrite(7, 0); //A
   digitalWrite(8, 1); //B
    }    
void enam()
  {
   digitalWrite(2, 1); //C
   digitalWrite(3, 1); //D 
   digitalWrite(4, 1); //E
   digitalWrite(5, 1); //G
   digitalWrite(6, 1); //F
   digitalWrite(7, 1); //A
   digitalWrite(8, 0); //B
    }


void loop() {
satu();    
delay(1000);
enam();
delay(1000);
}
