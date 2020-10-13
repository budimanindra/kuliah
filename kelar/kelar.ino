#include <SPI.h>
#include <MFRC522.h>


#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//I2C pins declaration
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

#define SS_PIN 10
#define RST_PIN 9




MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.


const int trigPin = 4;
const int echoPin = 3;
const int buzzer = 2;
const int Led_B = 5;
const int Led_G = 6;
const int Led_R = 7;

int button = 2;
int nilaibutton;
int count;

long duration;
int distance;
int safetyDistance;
long x;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(Led_B, OUTPUT);
  pinMode(Led_G, OUTPUT);
  pinMode(Led_R, OUTPUT);


  Serial.begin(9600);   // Initiate a serial communication

  lcd.begin(16, 2); //Defining 16 columns and 2 rows of lcd display
  lcd.backlight();//To Power ON the back light

  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522

  noTone(buzzer);
  Serial.println("Put your card to the reader...");
  Serial.println();

  nilaibutton = digitalRead(button);
  if (nilaibutton == 1) {
    count++;
    if (count == 1) {
    long x = 2592000000;
    }
    if (count == 2) {
    long x = 10;
    count = 0;
    }
  }
}
void loop()
{
  delay(x);
  digitalWrite(Led_G, LOW);
  digitalWrite(Led_B, HIGH);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  safetyDistance = distance;
  Serial.println(safetyDistance);

  if (safetyDistance > 30) {
    Serial.println("Starting Alarm 5...");
    lcd.clear();
    digitalWrite(Led_B, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter your ID");
    lcd.setCursor(0, 1);
    lcd.print("   in 5 ");
    digitalWrite(Led_R, HIGH);
    delay(700);
    lcd.clear();
    digitalWrite(Led_R, LOW);
    delay(300);
    Serial.println("Starting Alarm 4...");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter your ID");
    lcd.setCursor(0, 1);
    lcd.print("   in 4 ");
    digitalWrite(Led_R, HIGH);
    delay(700);
    lcd.clear();
    digitalWrite(Led_R, LOW);
    delay(300);
    Serial.println("Starting Alarm 3...");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter your ID");
    lcd.setCursor(0, 1);
    lcd.print("   in 3 ");
    digitalWrite(Led_R, HIGH);
    delay(700);
    lcd.clear();
    digitalWrite(Led_R, LOW);
    delay(300);
    Serial.println("Starting Alarm 2...");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter your ID");
    lcd.setCursor(0, 1);
    lcd.print("   in 2 ");
    digitalWrite(Led_R, HIGH);
    delay(700);
    lcd.clear();
    digitalWrite(Led_R, LOW);
    delay(300);
    Serial.println("Starting Alarm 1...");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter your ID");
    lcd.setCursor(0, 1);
    lcd.print("   in 1 ");
    digitalWrite(Led_R, HIGH);
    delay(700);
    lcd.clear();
    digitalWrite(Led_R, LOW);
    delay(300);
    digitalWrite(Led_B, LOW);
    tone(buzzer, 700);
    digitalWrite(Led_R, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("We will call");
    lcd.setCursor(0, 1);
    lcd.print("the Police");
    Serial.println ("Buzzer ON");
  }

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
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "04 0B 6B 8A 7E 29 80")//E-KTP INDRA
  {
    digitalWrite(Led_B, LOW);
    lcd.clear();
    lcd.print("E-KTP INDRA");
    Serial.println ("E-KTP INDRA");
    noTone(buzzer);
    Serial.println ("Buzzer OFF");
    digitalWrite(Led_R, LOW);
    digitalWrite(Led_G, HIGH);
    delay(2000);
    digitalWrite(Led_G, LOW);
    Serial.println("Authorized access");
    Serial.println();
  }

  else if (content.substring(1) == "FB F2 1D 1B") // akses tag indra
  {
    digitalWrite(Led_B, LOW);
    lcd.clear();
    lcd.print("E-KTP MARWAN");
    Serial.println ("E-KTP MARWAN");
    noTone(buzzer);
    Serial.println ("Buzzer OFF");
    digitalWrite(Led_R, LOW);
    digitalWrite(Led_G, HIGH);
    delay(2000);
    digitalWrite(Led_G, LOW);
    Serial.println("Authorized access");
    Serial.println();
  }

  else   {
    Serial.println("AKSES GAGAL");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("UNKNOWN USER");
  }
}
