#include <SD.h>
#include <SPI.h>
#include <Ultrasonic.h>
#include <DS3231.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LCD.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22
#define SensorPin A0            
#define samplingInterval 20
#define printInterval 1000
#define ArrayLength  40
#define RelayPIN 7
#define echoPIN 8
#define trigPIN 9
#define CSPIN 10

int pHArray[ArrayLength];
int pHArrayIndex=0;
static float pHValue,voltage;

float temperature;
int duration;
byte kuantitas, jarak;

const int OnHour = 17;
const int OnMin = 00;
const int OffHour = 05;
const int OffMin = 00;

File myFile;

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

DS3231  rtc(SDA, SCL);

Time t;

void setup() {
  Serial.begin(115200);
  rtc.begin();
  dht.begin();
  lcd.begin(20,4);
  lcd.backlight();
  pinMode(trigPIN, OUTPUT);
  pinMode(echoPIN, INPUT);
  pinMode(CSPIN, OUTPUT);
  pinMode(RelayPIN, OUTPUT);
  digitalWrite(RelayPIN, HIGH);
  if (SD.begin())
  {
    Serial.println("SD card is ready to use.");
    } else
    {
    Serial.println("SD card initialization failed");
    return;
    }
    }

void loop(){  

  //cek waktu yang ada di catat oleh rtc untuk menyala atau mematikan GrowLight
  t = rtc.getTime();  
  if(t.hour == OnHour && t.min == OnMin)
  {
  digitalWrite(RelayPIN,LOW);
  }
    
  else if(t.hour == OffHour && t.min == OffMin)
  {
  digitalWrite(RelayPIN,HIGH);
  }  

  //melakukan pengukuran pH, suhu, dan ketinggian air setiap detik
  static unsigned long samplingTime = millis();
  static unsigned long printTime = millis();
  if(millis()-samplingTime > samplingInterval)
  {
      pHArray[pHArrayIndex++]=analogRead(SensorPin);
      if(pHArrayIndex==ArrayLength)pHArrayIndex=0;
      voltage = avergearray(pHArray, ArrayLength)*5.0/1024;
      pHValue = 2.13121 * voltage + 2.66524;
      temperature = dht.readTemperature();
      bacajarak();
      samplingTime=millis();
  }
  if(millis() - printTime > printInterval)
  {
    printTime=millis();
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
  simpandata();
  String datakirim = String(kuantitas) + "#" + String(temperature) + "#" + String(pHValue);
  Serial.println(datakirim);
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
  if (jarak >= 21){
    kuantitas = 1;
  }
  else if (jarak >= 15 && jarak <21 ){
    kuantitas = 2;
  }
  else if (jarak >= 10 && jarak <15){
    kuantitas = 3;
  }
}

//fungsi untuk menampilkan hasil pembacaan sensor ke LCD
void tampilanlcd(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Hidroponik  Indoor");
  lcd.setCursor(0, 1);
  lcd.print("kuantitas air = ");
  if (jarak <10){
    lcd.print("+");
  }
  lcd.print(kuantitas);
  lcd.print("L");
  lcd.setCursor(0, 2);
  lcd.print("suhu = ");
  lcd.print(temperature);
  lcd.print("C");
  lcd.setCursor(0, 3);
  lcd.print("pH air = ");
  lcd.print(pHValue);
}

//fungsi untuk menyimpan hasil pembacaan sensor ke microSD pada data logger
void simpandata(){
  myFile = SD.open("HLOGGER.txt", FILE_WRITE);
  if (myFile) {    
    myFile.print(rtc.getDOWStr());
    myFile.print(",");
    myFile.print(rtc.getDateStr());
    myFile.print(",");
    myFile.print(rtc.getTimeStr());
    myFile.print(",");    
    myFile.print(kuantitas);
    myFile.print(",");  
    myFile.print(temperature);
    myFile.print(",");    
    myFile.println(pHValue);
    myFile.close();
  }
}

double avergearray(int* arr, int number){
  int i;
  int max,min;
  double avg;
  long amount=0;
  if(number<=0){
    return 0;
  }
  if(number<5){
    for(i=0;i<number;i++){
      amount+=arr[i];
    }
    avg = amount/number;
    return avg;
  }else{
    if(arr[0]<arr[1]){
      min = arr[0];max=arr[1];
    }
    else{
      min=arr[1];max=arr[0];
    }
    for(i=2;i<number;i++){
      if(arr[i]<min){
        amount+=min; 
        min=arr[i];
      }else {
        if(arr[i]>max){
          amount+=max; 
          max=arr[i];
        }else{
          amount+=arr[i];
        }
      }//if
    }//for
    avg = (double)amount/(number-2);
  }//if
  return avg;
}
