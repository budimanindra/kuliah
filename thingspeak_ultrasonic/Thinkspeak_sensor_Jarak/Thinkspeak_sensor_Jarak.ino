#include <ThingSpeak.h>
#include <WiFi.h>

const int trigPin = 23;
const int echoPin = 22;

// defenisi variabel

long duration;
int distance;

// Hostpot
const char *ssid =  "new2";
const char *pass =  "qwerty1234";

WiFiClient client;

//thingspeak settings
unsigned long channel = 1072327; //your channel ID number
const char *apiKey = "ETKJ5X4H405QHUUQ"; //your channel write API Key

//int lum, i = 0;

void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(115200);
  delay(10);

  //connect to WiFi
  Serial.print("Connecting to: "); Serial.println(ssid);
  WiFi.begin(ssid, pass);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nWiFi connected\n");
  ThingSpeak.begin(client); //initialize ThingSpeak
  
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(200);

  int x = ThingSpeak.writeField(channel, 1, distance, apiKey);
  if (x == 200) {
    Serial.println("Data " + String(distance));
    Serial.print("distance: "); Serial.println(distance);
    Serial.println("Update to ThingSpeak Successful.");
  }
  else {
    Serial.println("Data " + String(distance));
    Serial.println("Problem updating data. HTTP error code " + String(x));
  }

  int y = ThingSpeak.writeField(channel, 2, temperature, apiKey);
  if (y == 200) {
    Serial.println("Data " + String(temperature));
    Serial.print("distance: "); Serial.println(temperature);
    Serial.println("Update to ThingSpeak Successful.");
  }
  else {
    Serial.println("Data " + String(temperature));
    Serial.println("Problem updating data. HTTP error code " + String(x));
  }

  Serial.println("Waiting...\n");
  delay(15000);
}
