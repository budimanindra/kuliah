#include <Ultrasonic.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LCD.h>
#define echoPIN 8
#define trigPIN 9

int duration;
int kuantitas, jarak;

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

void setup() {
  Serial.begin(115200);
  lcd.begin(20,4);
  lcd.backlight();
  pinMode(trigPIN, OUTPUT);
  pinMode(echoPIN, INPUT);
  }

void loop(){  
  bacajarak();
  tampilanlcd();
  delay(1000);
}

//fungsi untuk membaca ketinggian jarak antara bak penampungan dengan sensor
void bacajarak(){
  digitalWrite(trigPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPIN, LOW);
  duration = pulseIn(echoPIN, HIGH);
  jarak = duration*0.034/2;
  kuantitas = -0.2856*jarak + 6.7947;
}

//fungsi untuk menampilkan hasil pembacaan sensor ke LCD
void tampilanlcd(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Hidroponik  Indoor");
  lcd.setCursor(0, 1);
  lcd.print("jarak = ");
  lcd.print(jarak);
  lcd.print("cm");
  lcd.setCursor(0, 2);
  lcd.print("kuantitas = ");
  lcd.print(kuantitas);
  lcd.print("L");
}
