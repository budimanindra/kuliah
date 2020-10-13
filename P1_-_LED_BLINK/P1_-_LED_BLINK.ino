int hijau = 2;
int kuning = 3;
int merah = 4;

void setup() {
  pinMode (hijau, OUTPUT);
  pinMode (kuning, OUTPUT);
  pinMode (merah, OUTPUT);
}

void loop() {
  digitalWrite (hijau, HIGH);
  delay (2000);
  digitalWrite (kuning, HIGH);
  delay (1000);
  digitalWrite (hijau, LOW);
  digitalWrite (kuning, LOW);
  digitalWrite (merah, HIGH);
  delay (3000);
  digitalWrite (merah, LOW);
  }
