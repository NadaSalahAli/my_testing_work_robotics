// Motor A
#define ENA 5
#define IN1 8
#define IN2 9

// Motor B
#define ENB 6
#define IN3 10
#define IN4 11

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {

  // الموتورين للأمام
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  delay(3000);

  // توقف
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  delay(2000);

  // الموتورين للخلف
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, 200);
  analogWrite(ENB, 200);

  delay(3000);

  // توقف
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  delay(2000);
}
