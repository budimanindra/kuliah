const int trigPin = 7;
const int echoPin = 8;
const int pinBuzzer = 6;


#include <SPI.h>
#include <MFRC522.h>
#define pinSDA 10
#define pinRST 9
MFRC522 RFID(pinSDA, pinRST);

long duration;
int distance;
int waktu = 5;

void setup() {

  SPI.begin();
  RFID.PCD_Init();
  Serial.println("VEHICLE SAFETY SYSTEM");
  Serial.println("");
  Serial.println("PUT YOUR E-KTP");
  Serial.println();

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

}



void loop() {

  if ( ! RFID.PICC_IsNewCardPresent())
  {
    return;
  }

  if ( ! RFID.PICC_ReadCardSerial()) {
    return;
  }
  String content = "";
  byte letter;
  for (byte i = 0; i < RFID.uid.size; i++) {
    content.concat(String(RFID.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(RFID.uid.uidByte[i], HEX));
  }
  content.toUpperCase();

  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;

  // Prints the distance on the Serial Monitor
  delay (1000);
  Serial.print("Distance: ");
  Serial.println(distance);

  if (content.substring(1) == "9A 83 F1 0A")
  {
    Serial.println("UNLOCKED");
    if (distance > distance + 5)
    {
      Serial.println("ALARM ON");
      Serial.println();
      digitalWrite(pinBuzzer, HIGH);

      if (content.substring(1) == "9A 83 F1 0A")
      {
        Serial.println("ALARM OFF");
        Serial.println();
        digitalWrite(pinBuzzer,   LOW);
        delay (1000);
      }
    }
    else if (distance < distance + 5)
    {
      Serial.println("ALARM ON");
      Serial.println();
      digitalWrite(pinBuzzer, HIGH);
      if (content.substring(1) == "9A 83 F1 0A")
        Serial.println("ALARM OFF");
      Serial.println();
      digitalWrite(pinBuzzer,   LOW);
      delay (1000);
    }
  }
}
