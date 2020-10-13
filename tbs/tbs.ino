#include <LiquidCrystal.h>              //menambahkan library LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  //pin yang digunakan

void setup() {
  lcd.begin(16, 2);                     //set ukuran lCD 16x2
}

void loop() {
  lcd.setCursor(0,0);                   //baris pertama
  lcd.print(" Test LCD Tanpa I2C");     //menampilkan kata
  
  lcd.setCursor(0, 1);                  //baris kedua
  lcd.print(" KelasRobot.com");         //menampilkan kata
}
