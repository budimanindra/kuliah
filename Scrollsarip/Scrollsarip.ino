// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
 lcd.setCursor(0,5);
 lcd.print("indra");
 lcd.clear();
 delay(500);
 lcd.setCursor(0,6);
 lcd.print("indra");
 lcd.clear();
 delay(500);
 lcd.setCursor(0,7);
 lcd.print("indra");
 lcd.clear();
 delay(500);
 lcd.setCursor(7,1);
 lcd.print("indra");
 lcd.clear();
 delay(500);
 lcd.setCursor(8,1);
 lcd.print("indra");
 lcd.clear();
 delay(500);
 lcd.setCursor(9,1);
 lcd.print("indra");
 lcd.clear();
 delay(500);
 lcd.setCursor(10,1);
 lcd.print("indra");
 lcd.clear();
 delay(500);
}
