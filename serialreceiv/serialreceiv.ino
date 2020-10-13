long distance; //Initialized variable to store recieved data

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
}

void loop() {
  Serial.read(distance,20);
  Serial.print("Data dari sensor jarak = ");
  Serial.println(distance); //Read the serial data and store in var
  delay(1000);
}
