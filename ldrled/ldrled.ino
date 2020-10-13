byte ldr= A0;
byte led= 13;
byte led2= 12;
int nilai;

void setup(){
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(led2, HIGH);
  nilai= analogRead(ldr);
  Serial.print("Nilai LDR: ");
  Serial.println(nilai);

  if(nilai < 500){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }
  
}
