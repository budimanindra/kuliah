#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(28, 30, 5, 4, 3, 2);
const byte rows = 4;
const byte cols = 4;
int coloumn = 0;
char keys [rows][cols] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
 };

  byte rowPins [rows] = {9, 8, 7, 6};
  byte colPins [cols]= {13, 12, 11, 10};
  Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();
if(key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0' || key == 'A' || key == 'B' || key == 'D' ||
   key == '*' || key == '#' || key == 'C'){
lcd.setCursor(coloumn, 0);
lcd.print(key);
coloumn = coloumn + 1;
  if(coloumn> 15){
lcd.clear();
coloumn = 0;
  }
}
}

