#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);
const byte ROWS = 4;
const byte COLS = 3;
Servo myservo;   
int pos = 0;


const char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
  };
const byte rowPins[ROWS] = {4,3,2,1};
const byte colPins[COLS] = {7,6,5};

Keypad    keypad { makeKeymap(keys), rowPins, colPins, ROWS, COLS };

void setup() {
lcd.begin(16, 2);
Serial.begin(9600);
myservo.attach(0);
lcd.print("PASSWORD: ");
}


void loop() {
  lcd.setCursor(11,0);
  char key = keypad.getKey();
if(key == '1' || key == '2' || key == '3' ||
   key == '4' || key == '5' || key == '6' ||
   key == '7' || key == '8' || key == '9' ||
   key == '*' || key == '0' || key == '#'){
  lcd.print(key);
    
if(key == '1'){
  lcd.setCursor (0,1);
  lcd.print("PINTU  TERBUKA");
  for(pos = 0; pos <= 180; pos += 1) 
  {                                  
  myservo.write(pos);                                     
  }
  delay(3000);
  lcd.clear();
  for(pos = 180; pos >= 0; pos -= 1) 
  {                                  
  myservo.write(pos);
  }
  lcd.setCursor(0,0);
  lcd.print("PASSWORD: ");
  lcd.setCursor (0,1);
  lcd.print("PINTU TERKUNCI");
  lcd.setCursor(11,0);
  }
  
else if(key == '2'){
  lcd.setCursor (0,1);
  lcd.print("PINTU TERKUNCI");
  for(pos = 180; pos >= 0; pos -= 1) 
  {                                  
  myservo.write(pos);
  }  
  }
  
else{
  lcd.setCursor (0,1);
  lcd.print("PASSWORD SALAH");
}
   }}
