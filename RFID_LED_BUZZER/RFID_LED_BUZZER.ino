#include <SPI.h>
#include "pitches.h"
#include <MFRC522.h>
#define pinSDA 10
#define pinRST 9
MFRC522 RFID(pinSDA, pinRST);

// Melodies definition: access, welcome and rejection
int access_melody[] = {NOTE_G4,0,NOTE_A4,0, NOTE_B4,0,NOTE_A4,0,NOTE_B4,0, NOTE_C5,0};
int access_noteDurations[] = {8,8,8,8,8,4,8,8,8,8,8,4};
int fail_melody[] = {NOTE_G2,0,NOTE_F2,0,NOTE_D2,0};
int fail_noteDurations[] = {8,8,8,8,8,4};

int redPin = 7;
const int pinBuzzer = 8;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  RFID.PCD_Init();
  Serial.println("RFID indomaker.com");
  Serial.println("");
  Serial.println("Tap Kartu/Gantungan !");
  Serial.println();
}
void loop() {
  if ( ! RFID.PICC_IsNewCardPresent()) {
    return;
  }
  if ( ! RFID.PICC_ReadCardSerial()) {
    return;
  }
  Serial.print("ID Tag :");
  String content = "";
  byte letter;
  for (byte i = 0; i < RFID.uid.size; i++) {
    Serial.print(RFID.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(RFID.uid.uidByte[i], HEX);
    content.concat(String(RFID.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(RFID.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print ("Message :");
  content.toUpperCase();
  if(content.substring(1)=="04 0B 6B 8A 7E 29 80")// akses ktp indra
  {
    Serial.println("Akses Diberi");
    Serial.println();
    digitalWrite(redPin, HIGH);
    
      for (int i = 0; i < 12; i++){ // play welcome sound
      int access_noteDuration = 1000/access_noteDurations[i];
      tone(pinBuzzer, access_melody[i],access_noteDuration);
      int access_pauseBetweenNotes = access_noteDuration * 1.30;
      delay(access_pauseBetweenNotes);
      noTone(pinBuzzer);
    }
  }

    else if(content.substring(1)=="9A 83 F1 0A")// akses tag indra
  {
    Serial.println("Akses Diberi");
    Serial.println();
    void dering_pendek();
    digitalWrite(redPin, HIGH);
        digitalWrite(redPin, HIGH);
    
      for (int i = 0; i < 12; i++){ // play welcome sound
      int access_noteDuration = 1000/access_noteDurations[i];
      tone(pinBuzzer, access_melody[i],access_noteDuration);
      int access_pauseBetweenNotes = access_noteDuration * 1.30;
      delay(access_pauseBetweenNotes);
      noTone(pinBuzzer);
  }
  }
  else if(content.substring(1)=="FB F2 1D 1B")// akses tag indra
  {
    Serial.println("Akses Diberi");
    Serial.println();
    void dering_pendek();
    digitalWrite(redPin, HIGH);
        digitalWrite(redPin, HIGH);
    
      for (int i = 0; i < 12; i++){ // play welcome sound
      int access_noteDuration = 1000/access_noteDurations[i];
      tone(pinBuzzer, access_melody[i],access_noteDuration);
      int access_pauseBetweenNotes = access_noteDuration * 1.30;
      delay(access_pauseBetweenNotes);
      noTone(pinBuzzer);
  }
  }
  else {
    Serial.println("Akses Tidak Diberi");
        void dering_panjang();
        digitalWrite(redPin, HIGH);
        delay (250);
        digitalWrite(redPin, LOW);
        delay (250);
        digitalWrite(redPin, HIGH);
        delay (250);
        digitalWrite(redPin, LOW);
        delay (250);
        digitalWrite(redPin, HIGH);
        delay (250);
        digitalWrite(redPin, LOW);
        delay (250);
        for (int i = 0; i < 6; i++){ // playa rejection sound
      int fail_noteDuration = 1000/fail_noteDurations[i];
      tone(pinBuzzer, fail_melody[i],fail_noteDuration);
      int fail_pauseBetweenNotes = fail_noteDuration * 1.30;
      delay(fail_pauseBetweenNotes);
      noTone(pinBuzzer);
    }
    delay(1000);
  }
  
}
