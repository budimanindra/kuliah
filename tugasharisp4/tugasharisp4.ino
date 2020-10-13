#include <LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
char rifky1[6] = {'r', 'i', 'f', 'k','y'};
char rifky2[6] = {'\0', 'r', 'i', 'f', 'k','y'};
char asuna1[6] = {'a', 's', 'u', 'n','a'};
char asuna2[6] = {'\0', 'a', 's', 'u', 'n','a'};
char shino1[6] = {'s', 'h', 'i', 'n','o'};
char shino2[6] = {'\0', 's', 'h', 'i', 'n','o'};
void setup() {
lcd.begin(16, 2);
}
void loop() {
for (int positionCounter = 0; positionCounter < 39;
positionCounter++)
{ lcd.setCursor(16,0);
lcd.print("AdaYangTegakTapiBukanKeadlian");
lcd.scrollDisplayLeft();
delay(50);
}
lcd.clear();
for (int positionCounter = 0; positionCounter <30;
positionCounter++)
{
lcd.setCursor(17,1);
lcd.print("Rifky");
lcd.scrollDisplayLeft();
delay(50);
}
lcd.clear();
for (int positionCounter = 0; positionCounter <3;
positionCounter++)
{
for (int i = 0; i < 6; i++){
lcd.setCursor(15,0);
lcd.print(rifky1[i]);
lcd.setCursor(14,1);
lcd.print(rifky2[i]);
delay(300);
}
lcd.scrollDisplayLeft();
}
lcd.clear();
lcd.setCursor(12,0);
lcd.print("X");
lcd.setCursor(11,1);
lcd.print("X");
delay(500);
lcd.clear();
for (int positionCounter = 0; positionCounter <3;
positionCounter++)
for (int i = 0; i < 6; i++){
lcd.setCursor(11,0);
lcd.print(asuna1[i]);
lcd.setCursor(10,1);
lcd.print(asuna2[i]);
delay(300);
lcd.scrollDisplayLeft();
}//end of call intan
lcd.clear();
lcd.print("X");
lcd.print("X");
delay(500);
lcd.clear();
for (int positionCounter = 0; positionCounter <3;
positionCounter++)
for (int i = 0; i < 6; i++){
lcd.setCursor(7,0);
lcd.print(shino1[i]);
lcd.setCursor(6,1);
lcd.print(shino2[i]);
delay(300);
lcd.scrollDisplayLeft();
}}
