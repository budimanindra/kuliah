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
 lcd.setCursor(0,0);
 lcd.print("indra");
 for (int positionCounter = 0; positionCounter < 3; positionCounter++) {
 lcd.scrollDisplayRight();
 delay(150);
 }
 lcd.clear();

 lcd.setCursor(1,1);
 lcd.print("indra");
 for (int positionCounter = 0; positionCounter < 3; positionCounter++) {
 lcd.scrollDisplayRight();
 delay(150);
 }
 lcd.clear();

 lcd.setCursor(1,0);
 lcd.print("indra");
 for (int positionCounter = 0; positionCounter < 3; positionCounter++) {
 lcd.scrollDisplayRight();
 delay(150);
 }
 lcd.clear();

  lcd.setCursor(1,1);
 lcd.print("indra");
 for (int positionCounter = 0; positionCounter < 3; positionCounter++) {
 lcd.scrollDisplayRight();
 delay(150);
 }
 lcd.clear();

 lcd.setCursor(2,0);
 lcd.print("indra");
 for (int positionCounter = 0; positionCounter < 3; positionCounter++) {
 lcd.scrollDisplayRight();
 delay(150);
 }
 lcd.clear();

 lcd.setCursor(2,1);
 lcd.print("indra");
 for (int positionCounter = 0; positionCounter < 3; positionCounter++) {
 lcd.scrollDisplayRight();
 delay(150);
 }
 lcd.clear();
}
