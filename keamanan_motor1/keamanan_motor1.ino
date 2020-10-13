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

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  scan();
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

  if (content.substring(1) == "9A 83 F1 0A") // akses ktp indra
  {
    Serial.println("HELLO INDRA");
    Serial.println("VEHICLE HAS BEEN LOCKED");
    if (distance > distance + 5)
    {
      Serial.println("ALARM ON");
      Serial.println();
      infobuzzer ();
      if (content.substring(1) == "9A 83 F1 0A")
      {
        infobuzzer ();
        Serial.println("ALARM OFF");
        Serial.println();
        delay (2000);
      }
    }
    else if (distance < distance - 5)
    {
      Serial.println("ALARM ON");
      Serial.println();
      infobuzzer ();
      if (content.substring(1) == "9A 83 F1 0A")
        Serial.println("ALARM OFF");
      Serial.println();
      infobuzzer ();
    }
  }

  else {
    Serial.println("UNREGISTERED VEHICLE");
    Serial.println();
    delay(1000);
    scan();
  }

}

void scan() {
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
}

void infobuzzer() {
  digitalWrite(pinBuzzer, HIGH);    //buzzer bunyi dengan delay
  delay(200);                       //delay 200 milisecond
  digitalWrite(pinBuzzer, LOW);     //buzzer mati dengan delay
  delay(200);                       //delay 200 milisecond
  digitalWrite(pinBuzzer, HIGH);    //buzzer bunyi dengan delay
  delay(200);                       //delay 200 milisecond
  digitalWrite(pinBuzzer, LOW);     //buzzer mati dengan delay
  delay(1000);                      //delay 1000 milisecond
}
