const int relay = 2;
int lampuNyala = LOW;
int lampuMati = HIGH;

void setup() {
pinMode(relay, OUTPUT);
digitalWrite(relay, lampuMati);
}

void loop() {
digitalWrite(relay, lampuNyala);
delay(5000);
digitalWrite(relay, lampuMati);
delay(1000);
}
