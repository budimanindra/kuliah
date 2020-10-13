#include <Ultrasonic.h>
const int pinBuzzerl = 4;
const int pinBuzzerr = 3;


Ultrasonic ultral(5, 6);  // (Trig PIN,Echo PIN)
Ultrasonic ultrar(8, 7);  // (Trig PIN,Echo PIN)


#include <SPI.h>
#include <MFRC522.h>
#define pinSDA 10
#define pinRST 9
MFRC522 RFID(pinSDA, pinRST);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  RFID.PCD_Init();
  pinMode(pinBuzzerl, OUTPUT);
  pinMode(pinBuzzerr, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
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
  if (content.substring(1) == "9A 83 F1 0A") // akses ktp indra
  {
    Serial.print(ultral.Ranging(CM));
    Serial.print(ultrar.Ranging(CM));
    if (ultral.Ranging(CM) < 10) {
      Serial.println("Keamanan Parkir Kiri Aktif");
      if (ultral.Ranging(CM) > ultral.Ranging(CM) + 5) {
        digitalWrite(pinBuzzerl, HIGH);    //buzzer bunyi dengan delay
        delay(50);
      }
      else (ultral.Ranging(CM) < ultral.Ranging(CM) - 5); {
        digitalWrite(pinBuzzerl, HIGH);    //buzzer bunyi dengan delay
        delay(50);
      }
    }
    else if (ultrar.Ranging(CM) < 10) {
      Serial.println("Keamanan Parkir Kanan Aktif");
      if (ultrar.Ranging(CM) > ultrar.Ranging(CM) + 5) {
        digitalWrite(pinBuzzerr, HIGH);    //buzzer bunyi dengan delay
        delay(50);
      }
      else (ultrar.Ranging(CM) < ultrar.Ranging(CM) - 5); {
        digitalWrite(pinBuzzerr, HIGH);    //buzzer bunyi dengan delay
        delay(50);
      }
    }
  }
  else {
    Serial.println("Akses Tidak Diberi");
  }
}
