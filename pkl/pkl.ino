//ultrasonic 1
int echoPin1 =8;
int initPin1 =9;
int distance1 =0;

//ultrasonic 2
int echoPin2 =6;
int initPin2 =7;
int distance2 =0;

//ultrasonic 3
int echoPin3 =4;
int initPin3 =5;
int distance3 =0;




void setup() {

  pinMode(PIN13, OUTPUT); //buzzer 1
  pinMode(PIN13, OUTPUT); //buzzer 1 
  pinMode(PIN13, OUTPUT); //buzzer 1

  pinMode(initPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(initPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(initPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  Serial.begin(9600);
  
}

void loop() {
  
  distance1 = getDistance(initPin1, echoPin1);
  printDistance(1, distance1);
  delay(150);
  
  distance2 = getDistance(initPin2, echoPin2);
  printDistance(2, distance2);
  delay(150);
  
  distance3 = getDistance(initPin3, echoPin3);
  printDistance(3, distance3);
  delay(150);
  Serial.println("");
  delay(500);
  
}

int getDistance (int initPin, int echoPin){

 digitalWrite(initPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(initPin, LOW); 
 unsigned long pulseTime = pulseIn(echoPin, HIGH); 
 int distance = pulseTime/58;
 return distance;

}

 void printDistance(int id, int dist){
  
     Serial.print(id);
     Serial.print("------>");   
    Serial.print(dist, DEC);
    Serial.println(" cm");
    
 }

 void dering_panjang(){
digitalWrite(PIN13, HIGH);
delay(700); //memberikan nilai tunda 0.7 second
digitalWrite(PIN13, LOW);
delay(700);
}
