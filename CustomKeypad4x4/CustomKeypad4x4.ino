#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);

int coloumn;
int row;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char keys[ROWS][COLS] = {
  {'I','N','D'},
  {'R','A','K'},
  {'4','L',' '},
  {'4','#','C'}
 };
byte rowPins[ROWS] = {3, 2, 1, 0}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7, 6, 5, 4}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); 

void setup(){
  lcd.begin (16, 2);
  Serial.begin(9600);
}
  
void loop(){
  char key = customKeypad.getKey();
  if(key == 'I' || key == 'N' || key == 'D' ||
   key == 'R' || key == 'A' || key == 'K' ||
   key == '4' || key == 'L' || key == ' ' ||
   key == '4' || key == '#' || key == 'C'){
  lcd.setCursor(coloumn, row);
lcd.print(key);
coloumn = coloumn + 1;
  if(coloumn> 15){
  coloumn = 0;
  row = 1;
  }
  }}
