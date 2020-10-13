char data = 0;             
void setup() 
{
  Serial.begin(9600);         
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
}
void loop()
{
  if(Serial.available() > 0)  
  {
    data = Serial.read();  
    if(data == '1'){
    digitalWrite(2, LOW);
    }
    else if(data == '2'){      
    digitalWrite(2, HIGH);
    } 
    
    else if(data == '3'){
    digitalWrite(3, LOW); 
    }
    else if(data == '4'){      
    digitalWrite(3, HIGH); 
    } 
    }
}
