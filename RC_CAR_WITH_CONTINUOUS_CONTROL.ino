#include <SoftwareSerial.h>

// تهيئة البلوتوث على الدبابيس (2 لاستقبال RX، و 3 لإرسال TX)
SoftwareSerial bluetooth(2, 3); 

// دبابيس التحكم في اتجاه المواتير
const int motor1Pin1 = 9;
const int motor1Pin2 = 8;
const int motor2Pin1 = 7;
const int motor2Pin2 = 6;

// دبابيس التحكم في السرعة (Enable)
const int enableA = 10;
const int enableB = 5;

char command = 'S'; 

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  
  // ضبط دبابيس المواتير كـ OUTPUT
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  
  // إيقاف السيارة في البداية للحماية
  stopMotors(); 

  Serial.println("\n=== RC BLUETOOTH CAR INITIALIZED ===");
}

void loop() {
  // ضبط السرعة القصوى للمواتير (255) بشكل دائم
  analogWrite(enableA, 255); 
  analogWrite(enableB, 255);
  
  // التحقق من استقبال بيانات عبر البلوتوث
  if (bluetooth.available() > 0) {
    command = bluetooth.read();
    
    // تنفيذ الحركة بناءً على الحرف المستلم
    if (command == 'F') {
      moveForward();
      Serial.println("Moving Forward");
    } 
    else if (command == 'B') {
      moveBackward();
      Serial.println("Moving Backward");
    } 
    else if (command == 'L') {
      turnLeft();
      Serial.println("Turning Left");
    } 
    else if (command == 'R') {
      turnRight();
      Serial.println("Turning Right");
    } 
    else if (command == 'S') {
      stopMotors();
      Serial.println("Car Stopped");
    }
  }
}
ط
// دالات التحكم في الحركة والتوجيه (تم تصحيحها بناءً على توجيهاتك)

void moveForward() {
  // تم تعديلها لتتحرك للأمام مباشرة (أخذت قيم الدالة اليمين السابقة)
  digitalWrite(motor1Pin1, HIGH); digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH); digitalWrite(motor2Pin2, LOW);
}

void moveBackward() {
  // تم تعديلها لتتحرك للخلف مباشرة (أخذت قيم الدالة اليسار السابقة)
  digitalWrite(motor1Pin1, LOW);  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);  digitalWrite(motor2Pin2, HIGH);
}

void turnLeft() {
  // تم تعديلها لتحود لليسار (أخذت قيم الدالة الخلف السابقة)
  digitalWrite(motor1Pin1, HIGH); digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);  digitalWrite(motor2Pin2, HIGH);
}

void turnRight() {
  // تم تعديلها لتحود لليمين (أخذت قيم الدالة الأمام السابقة)
  digitalWrite(motor1Pin1, LOW);  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH); digitalWrite(motor2Pin2, LOW);
}

void stopMotors() {
  digitalWrite(motor1Pin1, LOW);  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);  digitalWrite(motor2Pin2, LOW);
}
