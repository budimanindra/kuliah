// include the library code:
#include <LiquidCrystal.h>
#include <LCD.h>

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
 delay(150);
 lcd.clear();

 lcd.setCursor(1,1);
 lcd.print("indra");
 delay(150);
 lcd.clear();

 lcd.setCursor(2,0);
 lcd.print("indra");
 delay(150);
 lcd.clear();

 lcd.setCursor(3,1);
 lcd.print("indra");
 delay(150);
 lcd.clear();

 lcd.setCursor(4,0);
 lcd.print("indra");
 delay(150);
 lcd.clear();

 lcd.setCursor(5,1);
 lcd.print("indra");
 delay(150);
 lcd.clear();

  lcd.setCursor(6,0);
 lcd.print("indra");
 delay(150);
 lcd.clear();

 lcd.setCursor(7,1);
 lcd.print("indra");
 delay(150);
 lcd.clear();

 lcd.setCursor(8,0);
 lcd.print("indra");
 delay(150);
 lcd.clear();

 lcd.setCursor(9,1);
 lcd.print("indra");
 delay(150);
 lcd.clear();

 lcd.setCursor(10,0);
 lcd.print("indra");
 delay(150);
 lcd.clear();

 lcd.setCursor(4,0);
 lcd.print("SARIP !!!");
 lcd.setCursor(4,1);
 lcd.print("SARIP !!!");
 delay (150);
 lcd.clear();
 
}
