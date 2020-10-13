//test program
#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(13,12,11,10,9,8);

const byte rows = 4;
const byte cols = 3;
int coloumn = 0;
int row;
char keys [rows][cols] = 
{
  {'I','N','D'},
  {'R','A','K'},
  {'4',' ','x'},
  {'4','#','C'}
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
if(key == 'I' || key == 'N' || key == 'D' ||
   key == 'R' || key == 'A' || key == 'K' ||
   key == '4' || key == ' ' || key == 'x' ||
   key == '4' || key == '#' || key == 'C'){
lcd.setCursor(coloumn, row);
lcd.print(key);
coloumn = coloumn + 1;
  
  if(coloumn> 15){
    lcd.clear();
    coloumn = 0;
    }
}
}
