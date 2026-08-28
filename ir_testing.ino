const int irSensor = 2;

void setup() {
  pinMode(irSensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(irSensor);

  Serial.print("IR Sensor: ");
  Serial.println(value);

  delay(200);
}
