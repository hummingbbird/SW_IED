#define PIN_LED 7

void setup() {
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, 0); //0이 켜져있는 거
  delay(1000);
}

void loop() {
  int n = 0;
  while (n<5) {
    digitalWrite(PIN_LED, 1);
    delay(100);
    digitalWrite(PIN_LED, 0);
    delay(100);

    n += 1;
  }
  digitalWrite(PIN_LED, 1);
  while(1) {}
}
