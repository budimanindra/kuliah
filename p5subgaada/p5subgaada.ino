#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(13,12,11,10,9,8);

const byte rows = 4;
const byte cols = 3;
int coloumn = 0;
int row;
char keys [rows][cols] = 
{
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
 };

  byte rowPins [rows] = {4, 3, 2, 1};
  byte colPins [cols]= {7, 6, 5};
  Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2);
Serial.begin(9600);
}

void loop() {
char key = keypad.getKey();
if(key == '1' || key == '2' || key == '3' ||
   key == '4' || key == '5' || key == '6' ||
   key == '7' || key == '8' || key == '9' ||
   key == '*' || key == '0' || key == '#'){
lcd.setCursor(coloumn, 0);
lcd.print(key);
coloumn = coloumn + 1;
  if(coloumn> 15){
lcd.clear();
coloumn = 0;
    }
}
}
