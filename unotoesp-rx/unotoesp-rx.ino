void setup(){
  Serial.begin(9600);
}

void loop(){
  String data = "";
  while (Serial.available()>0)
  {
    data += char (Serial.read());
  }
  data.trim();
  Serial.println("Data dari Arduino UNO : " + data);
  delay(500);
}

