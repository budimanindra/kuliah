#include <LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 3;
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {4, 3, 2, 1};
byte colPins[COLS] = {5, 6, 7};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

LiquidCrystal lcd (13, 12, 11, 10, 9, 8);

void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Arduino Keypad");
  delay(2000);
  lcd.clear();
}

void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("Press any key");
  char customKey = customKeypad.getKey();
  if (customKey)
  {
    lcd.setCursor(0, 1);
    lcd.print(customKey);
    lcd.print(" is pressed");
  }
}
