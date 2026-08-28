/*
===============================================================================
 LINE FOLLOWER WITH SPEED CONTROL
 Change speed by typing numbers in Serial Monitor
===============================================================================
*/

#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 10

#define IR_LEFT A0
#define IR_RIGHT A1

int motorSpeed = 150;
int irLeftValue = 0;
int irRightValue = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);
  
  stopCar();
  
  Serial.println("========================================");
  Serial.println("  LINE FOLLOWER WITH SPEED CONTROL");
  Serial.println("========================================");
  Serial.println("✅ System Ready!");
  Serial.println("📏 Place robot on black line");
  Serial.println();
  Serial.println("🎛️  Type a number (80-255) to change speed");
  Serial.print("   Current speed: ");
  Serial.println(motorSpeed);
  Serial.println("========================================");
  Serial.println();
}

void loop() {
  // Check for speed commands from Serial Monitor
  if (Serial.available() > 0) {
    int newSpeed = Serial.parseInt();
    if (newSpeed >= 80 && newSpeed <= 255) {
      motorSpeed = newSpeed;
      Serial.print("✅ Speed changed to: ");
      Serial.println(motorSpeed);
    }
  }
  
  // Read IR sensors
  irLeftValue = digitalRead(IR_LEFT);
  irRightValue = digitalRead(IR_RIGHT);
  
  // Line following logic
  if (irLeftValue == 0 && irRightValue == 0) {
    forward();
  }
  else if (irLeftValue == 1 && irRightValue == 0) {
    turnLeft();
  }
  else if (irLeftValue == 0 && irRightValue == 1) {
    turnRight();
  }
  else if (irLeftValue == 1 && irRightValue == 1) {
    stopCar();
    delay(100);
    backward();
    delay(200);
    stopCar();
    delay(100);
  }
  
  delay(50);
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  setMotorSpeed(motorSpeed, motorSpeed);
}

void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  setMotorSpeed(motorSpeed, motorSpeed);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  setMotorSpeed(motorSpeed, motorSpeed);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  setMotorSpeed(motorSpeed, motorSpeed);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  setMotorSpeed(0, 0);
}

void setMotorSpeed(int leftSpeed, int rightSpeed) {
  leftSpeed = constrain(leftSpeed, 0, 255);
  rightSpeed = constrain(rightSpeed, 0, 255);
  analogWrite(ENA, leftSpeed);
  analogWrite(ENB, rightSpeed);
}
