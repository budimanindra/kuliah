String arrData[2];

int kuantitas, biaya;

void setup(){
  Serial.begin(115200);
}

void loop(){
  String data = "";
  Serial.println("Meminta Data Dari Arduino...");    
  while (Serial.available()>0)
  {
    data += char (Serial.read());
  }
  data.trim();
  if(data != "")
    {
      int index = 0;
      for (int i=0; i<= data.length(); i++)
      {
        char delimiter = '#';
        if (data[i] != delimiter)
          arrData [index] += data[i];
        else
        index ++;
      }

      if(index == 1)
      {
        Serial.println("Berhasil menerima data dari Arduino");
        kuantitas   = arrData[0].toInt();
        biaya       = arrData[1].toInt();
        Serial.println("Kuantitas       : " + arrData[0]);
        Serial.println("Biaya           : " + arrData[1]);
      }
      arrData[0] = "";
      arrData[1] = "";
    }
  delay(15000);
}
