#include <SoftwareSerial.h>
#include <ThingerESP32.h>
#include <WiFiClientSecure.h>

SoftwareSerial DataSerial (12,13);

unsigned long previousMillis = 0;
const long interval = 3000;

String arrData[2];

//konfigurasi ThingerIO
#define USERNAME "budimanindra98@gmail.com"
#define DEVICE_ID "FarmIoT"
#define DEVICE_CREDENTIAL "7djM-LXsiQGI"

//PIN LED
#define LED_PIN 4

//variabel ThingerIO
ThingerESP32 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

//konfigurasi WiFi
const char* ssid = "JTE5";
const char* password = "hujansenja";

//variabel untuk menampung nilai sensor untuk dikirim ke thingerIO
int jarak;
float t;

void setup() {
  Serial.begin(9600);
  DataSerial.begin(9600);
  pinMode(LED_PIN, OUTPUT);

  //koneksi ke WiFi
  WiFi.begin (ssid, password);
  //cek koneksi
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    digitalWrite(LED_PIN, LOW);
  }
  digitalWrite(LED_PIN, HIGH);
  //hubungkan esp32 ke thingerIO
  thing["DataKirim"] >> [](pson & out)
  {
    out["ketinggian air"] = jarak;
    out["temperature"] = t;
  };
}

void loop() {
  //konfigrasi millis
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    String data = "";
    while(DataSerial.available()>0)
    {
      data += char(DataSerial.read());
    }
    data.trim();

    if(data != "")
    {
      int index = 0;
      for(int i=0; i<= data.length(); i++)
      {
        char delimiter = '#';
        if(data[i] != delimiter)
            arrData[index] += data[i];
        else
            index++;
      }

      //cek data yang dikirim lengkap
      if (index == 1){
        Serial.println ("Ketinggian air : " + arrData[0]);
        Serial.println ("Suhu           : " + arrData[1]);
      }

      //isi variabel yang akan dikirim
      jarak = arrData [0].toInt();
      t     = arrData [1].toFloat();

      //mengirim data
      thing.handle();
            
      arrData [0] = "";
      arrData [1] = "";

    }
    Serial.println("Ya");
  }
}
