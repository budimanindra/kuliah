#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
lcd.begin(16, 2);
lcd.setCursor(0,0);
lcd.print("KELOMPOK X");
lcd.setCursor(0,1);
lcd.print("INDRA BUDIMAN");
}

void loop() {
  for (int positionCounter = 0; positionCounter < 1; positionCounter++)
  {
    lcd.scrollDisplayLeft();
    delay(300);
  }
  for (int positionCounter = 0; positionCounter <15; positionCounter++)
  {
    lcd.scrollDisplayRight();
    delay(300);
  }
  for (int positionCounter = 0; positionCounter < 8; positionCounter++)
  {
    lcd.scrollDisplayLeft();
    delay(300);
  }
 delay(4000);
}

