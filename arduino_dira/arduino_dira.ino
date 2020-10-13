byte sensorInt = 0;
byte sensorInt1 = 1;
byte sensorInt2 = 4;
byte sensorInt3 = 5;

byte flowSensor_pin = 2;
byte flowSensor_pin1 = 3;
byte flowSensor_pin2 = 19;
byte flowSensor_pin3 = 18;

float konst = 4.5;
float konst1 = 4.5;
float konst2 = 4.5;
float konst3 = 4.5;
float debit_air;
float debit_air1;
float debit_air2;
float debit_air3;

volatile byte count;
volatile byte count1;
volatile byte count2;
volatile byte count3;

unsigned int flow_mlt;
unsigned int flow_mlt1;
unsigned int flow_mlt2;
unsigned int flow_mlt3;

unsigned long total_volume;
unsigned long total_volume1;
unsigned long total_volume2;
unsigned long total_volume3;
unsigned long totall_volume1;
unsigned long totall_volume2;
unsigned long totall_volume3;

unsigned long oldTime;
unsigned long oldTime1;
unsigned long oldTime2;
unsigned long oldTime3;

int trig = 11;           // membuat varibel trig yang di set ke-pin 11
int echo = 12;           // membuat variabel echo yang di set ke-pin 12
const int Relay = 10;   // membuat variabel relay yang di set ke-pin 10
long durasi, jarak;     // membuat variabel durasi dan jarak


void setup() {
  pinMode(trig, OUTPUT);    // set pin trig menjadi OUTPUT
  pinMode(echo, INPUT);     // set pin echo menjadi INPUT
  pinMode(Relay, OUTPUT);
  
  Serial.begin(115200);
  pinMode(flowSensor_pin, INPUT);
  digitalWrite(flowSensor_pin, HIGH);

  count        = 0;
  debit_air    = 0.0;
  flow_mlt     = 0;
  total_volume = 0;
  oldTime      = 0;

  attachInterrupt(sensorInt, countPulse, FALLING);
  
  Serial.begin(115200);
  pinMode(flowSensor_pin1, INPUT);
  digitalWrite(flowSensor_pin1, HIGH);

  count1        = 0;
  debit_air1    = 0.0;
  flow_mlt1     = 0;
  total_volume1 = 0;
  oldTime1      = 0;

  attachInterrupt(sensorInt1, countPulse1, FALLING);

  Serial.begin(115200);
  pinMode(flowSensor_pin2, INPUT);
  digitalWrite(flowSensor_pin2, HIGH);

  count2        = 0;
  debit_air2    = 0.0;
  flow_mlt2     = 0;
  total_volume2 = 0;
  oldTime2      = 0;

  attachInterrupt(sensorInt2, countPulse2, FALLING);

  Serial.begin(115200);
  pinMode(flowSensor_pin3, INPUT);
  digitalWrite(flowSensor_pin3, HIGH);

  count3        = 0;
  debit_air3    = 0.0;
  flow_mlt3     = 0;
  total_volume3 = 0;
  oldTime3      = 0;

  attachInterrupt(sensorInt3, countPulse3, FALLING);
}


void loop() {
  ultrasonic();
  if (jarak <= 5)
  {
    digitalWrite (Relay , HIGH);
    delay (5000);
    }

   if (jarak > 30 )
   {
    digitalWrite (Relay , LOW);
    delay (5000);
    }

    
  if ((millis() - oldTime) > 1000) {
    detachInterrupt(sensorInt);
    debit_air = ((1000.0 / (millis() - oldTime)) * count) / konst;
    oldTime = millis();
    flow_mlt = (debit_air / 60) * 1000;
    total_volume += flow_mlt;

    unsigned int frac;
    count = 0;

    attachInterrupt(sensorInt, countPulse, FALLING);
  }
  if ((millis() - oldTime1) > 1000) {
    detachInterrupt(sensorInt1);
    debit_air1 = ((1000.0 / (millis() - oldTime1)) * count1) / konst1;
    oldTime1 = millis();
    flow_mlt1 = (debit_air1 / 60) * 1000;
    total_volume1 += flow_mlt1;
    totall_volume1 = 10;

    unsigned int frac;
    count1 = 0;

    attachInterrupt(sensorInt1, countPulse1, FALLING);
  }
  
  if ((millis() - oldTime2) > 1000) {
    detachInterrupt(sensorInt2);
    debit_air2 = ((1000.0 / (millis() - oldTime2)) * count2) / konst2;
    oldTime2 = millis();
    flow_mlt2 = (debit_air2 / 60) * 1000;
    total_volume2 += flow_mlt2;
    totall_volume2 = 20;

    unsigned int frac;
    count2 = 0;

    attachInterrupt(sensorInt2, countPulse2, FALLING);
  }
  
  if ((millis() - oldTime3) > 1000) {
    detachInterrupt(sensorInt3);
    debit_air3 = ((1000.0 / (millis() - oldTime3)) * count3) / konst3;
    oldTime3 = millis();
    flow_mlt3 = (debit_air3 / 60) * 1000;
    total_volume3 += flow_mlt3;
    totall_volume3 = 30;

    unsigned int frac;
    count3 = 0;

    attachInterrupt(sensorInt3, countPulse3, FALLING);
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
  minta = "";
}

void countPulse(){
  count++;
}

void countPulse1(){
  count1++;
}
void countPulse2(){
  count2++;
}

void countPulse3(){
  count3++;
}

void ultrasonic (){
     // program dibawah ini agar trigger memancarakan suara ultrasonic
  digitalWrite(trig, LOW);
  delayMicroseconds(8);
  digitalWrite(trig, HIGH);
  delayMicroseconds(8);
  digitalWrite(trig, LOW);
  delayMicroseconds(8);

  durasi = pulseIn(echo, HIGH); // menerima suara ultrasonic
  jarak = (durasi / 2) / 29.1;  // mengubah durasi menjadi jarak (cm)
}   

void kirimdata(){
  String datakirim = String(jarak) + "#" + String(totall_volume1) + "#" + String(totall_volume2) + "#" + String(totall_volume3);
  Serial.println(datakirim);
  }
