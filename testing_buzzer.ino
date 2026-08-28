const int buzzer = 8;

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(buzzer, HIGH);  // Turn ON
  delay(1000);

  digitalWrite(buzzer, LOW);   // Turn OFF
  delay(1000);
}
