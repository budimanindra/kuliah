#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

const int trigPin = 4;
const int echoPin = 3;
const int buzzer = 2;

long duration;
int distance, distancex;
bool statusscan = false;

String ektp = "";

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);


  Serial.begin(9600);   // Initiate a serial communication

  lcd.begin(16, 2); //Defining 16 columns and 2 rows of lcd display
  lcd.backlight();//To Power ON the back light

  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522

  noTone(buzzer);
  Serial.println("Put your card to the reader...");
  Serial.println();
}

void loop()
{
  jarak();
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  content.toUpperCase();
  delay (1000);
  if (content.substring(1) == "04 0B 6B 8A 7E 29 80")//E-KTP INDRA
  {
    distancex = distance;
    Serial.println(distancex);
    alarmoff();
    statusscan = true;
    Serial.println ("Sistem Keamanan Aktif");
    while (1) {
      jarak();
      while ((statusscan == true) && distance >= distancex + 5) {
        alarmon();
        // Look for new cards
        if ( ! mfrc522.PICC_IsNewCardPresent())
        {
          return;
        }
        // Select one of the cards

        if ( ! mfrc522.PICC_ReadCardSerial())
        {
          return;
        }
        //Show UID on serial monitor
        Serial.print("UID tag :");
        String content2 = "";
        byte letter;
        for (byte i = 0; i < mfrc522.uid.size; i++)
        {
          Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
          Serial.print(mfrc522.uid.uidByte[i], HEX);
          content2.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
          content2.concat(String(mfrc522.uid.uidByte[i], HEX));
        }
        Serial.println();
        Serial.print("Message : ");
        content.toUpperCase();
        if (content.substring(1) == "04 0B 6B 8A 7E 29 80") { //E-KTP INDRA
          statusscan = false;
          alarmoff();
        }
        if (statusscan == false) {
          break;
        }
      }
    }
  }
}

void jarak() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);
  delay (500);
}

void alarmon() {
  Serial.println("Starting Alarm 3...");
  delay(1000);
  Serial.println("Starting Alarm 2...");
  delay(1000);
  Serial.println("Starting Alarm 1...");
  delay(1000);
  tone(buzzer, 1000);
  Serial.println ("Buzzer ON");
}

void alarmoff() {
  Serial.println("Alarm OFF");
  noTone(buzzer);
}
