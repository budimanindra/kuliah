#include <Ultrasonic.h>
#include <DS3231.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LCD.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

int Relay = 7;
const int echoPin = 8;
const int trigPin = 9;

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

DS3231  rtc(SDA, SCL);
Time t;
float temperature, lembab, pH;
int duration, jarak;

const int OnHour = 17;
const int OnMin = 00;
const int OffHour = 17;
const int OffMin = 02;

void setup() {
  Serial.begin(115200);
  rtc.begin();
  dht.begin();
  lcd.begin(20,4);
  lcd.backlight();
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, HIGH);
}

void loop(){  
  
  t = rtc.getTime();
  
  if(t.hour == OnHour && t.min == OnMin)
  {
  digitalWrite(Relay,LOW);
  }
    
  else if(t.hour == OffHour && t.min == OffMin)
  {
  digitalWrite(Relay,HIGH);
  }  

  String minta = "";
  
  while(Serial.available()>0)
  {
    minta += char(Serial.read());
  }
  minta.trim();
  if(minta == "Meminta Data Dari Arduino...")
  {
    kirimdata();
  }

  //menunjukkan data di LCD
  tampilanlcd();
  
  //mengosongkan variabel minta dan waktu cek tiap sedetik
  minta = "";
  delay(1000);
}

void kirimdata(){
  temperature = dht.readTemperature();
  lembab = dht.readHumidity();
  bacajarak();
  String datakirim = String(jarak) + "#" + String(temperature) + "#" + String(lembab);
  Serial.println(datakirim);
  }

void bacajarak(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  jarak = duration*0.034/2;
}

void tampilanlcd(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Hidroponik  Indoor");
  lcd.setCursor(0, 1);
  lcd.print("kuantitas air = ");
  lcd.print(jarak);
  lcd.print("L");
  lcd.setCursor(0, 2);
  lcd.print("suhu = ");
  lcd.print(temperature);
  lcd.print("C");
  lcd.setCursor(0, 3);
  lcd.print("pH air = ");
  lcd.print(lembab);
}
