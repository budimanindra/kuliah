#include <SD.h>
#include <SPI.h>
#include <DS3231.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LCD.h>

int kuantitas, biaya;

byte sensorInt = 0;
byte flowsensor = 2;

//program yudi
volatile byte pulseCount;

float debit;
unsigned int flowmlt;
unsigned long totalmlt;
unsigned long oldTime;

float konstanta = 4.5; //konstanta flow meter
//program yudi


LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);

DS3231  rtc(SDA, SCL);

void setup() {
  Serial.begin(115200);
  rtc.begin();
  lcd.begin(20,4);
  lcd.backlight();

  //program yudi
    pinMode(flowsensor, INPUT);
  digitalWrite(flowsensor, HIGH);

  pulseCount = 0;
  debit = 0.0;
  flowmlt = 0;
  totalmlt = 0;
  oldTime = 0;

  attachInterrupt(sensorInt, pulseCounter, FALLING);
  //program yudi
}

void loop(){  
  if ((millis() - oldTime) > 1000)
  {
    detachInterrupt(sensorInt);
    debit = ((1000.0 / (millis() - oldTime)) * pulseCount) / konstanta;
    oldTime = millis();
    flowmlt = (debit / 60) * 1000;
    totalmlt += flowmlt;
    biaya = totalmlt * 1;
    
    pulseCount = 0;

    attachInterrupt(sensorInt, pulseCounter, FALLING);
  }
  
  //melakukan komunikasi dengan nodeMCU ESP32 setiap detik kemudian mengirim hasil pembacaan sensor ke ESP32
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

  tampilanlcd();
  
  minta = "";
  delay(1000);
}

//fungsi untuk mengirim data ke ESP32
void kirimdata(){
  String datakirim = String(totalmlt) + "#" + String(biaya);
  Serial.println(datakirim);
  }

//fungsi untuk menampilkan hasil pembacaan sensor ke LCD
void tampilanlcd(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Water Meter Digital");
  lcd.setCursor(0, 1);
  lcd.print(rtc.getDateStr());
  lcd.setCursor(0, 2);
  lcd.print("kuantitas = ");
  lcd.print(totalmlt);
  lcd.print("mL");
  lcd.setCursor(0, 3);
  lcd.print("biaya = ");
  lcd.print(biaya);
}

void pulseCounter()
{
  // Increment the pulse counter
  pulseCount++;
}
