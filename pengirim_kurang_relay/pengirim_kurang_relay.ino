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
#define printInterval 800
#define ArrayLenth  40    //times of collection
int pHArray[ArrayLenth];   //Store the average value of the sensor feedback
int pHArrayIndex=0;
static float pHValue,voltage;


File myFile;

DHT dht(DHTPIN, DHTTYPE);

int Relay = 7;
const int echoPin = 8;
const int trigPin = 9;
int pinCS = 10;

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
  pinMode(pinCS, OUTPUT);
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, HIGH);
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

  static unsigned long samplingTime = millis();
  static unsigned long printTime = millis();
  if(millis()-samplingTime > samplingInterval)
  {
      pHArray[pHArrayIndex++]=analogRead(SensorPin);
      if(pHArrayIndex==ArrayLenth)pHArrayIndex=0;
      voltage = avergearray(pHArray, ArrayLenth)*5.0/1024;
      pHValue = 2.13121 * voltage + 2.66524;
      samplingTime=millis();
  }
  if(millis() - printTime > printInterval)   //Every 800 milliseconds, print a numerical, convert the state of the LED indicator
  {
    printTime=millis();
  }
  
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
    //menyimpan data di microSD
  simpandata();
  String datakirim = String(jarak) + "#" + String(temperature) + "#" + String(pHValue);
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
  lcd.print(pHValue);
}

void simpandata(){
    myFile = SD.open("HLOGGER.txt", FILE_WRITE);
  if (myFile) {    
    myFile.print(rtc.getDOWStr());
    myFile.print(",");
    myFile.print(rtc.getDateStr());
    myFile.print(",");
    myFile.print(rtc.getTimeStr());
    myFile.print(",");    
    myFile.print(jarak);
    myFile.print(",");  
    myFile.print(temperature);
    myFile.print(",");    
    myFile.println(pHValue);
    myFile.close(); // close the file
  }
}

double avergearray(int* arr, int number){
  int i;
  int max,min;
  double avg;
  long amount=0;
  if(number<=0){
    Serial.println("Error number for the array to avraging!/n");
    return 0;
  }
  if(number<5){   //less than 5, calculated directly statistics
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
        amount+=min;        //arr<min
        min=arr[i];
      }else {
        if(arr[i]>max){
          amount+=max;    //arr>max
          max=arr[i];
        }else{
          amount+=arr[i]; //min<=arr<=max
        }
      }//if
    }//for
    avg = (double)amount/(number-2);
  }//if
  return avg;
}
