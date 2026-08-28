// دبابيس مستشعر الألتراسونيك
const int trigPin = 11;
const int echoPin = 12;

// دبابيس التحكم في اتجاه المواتير
const int motor1Pin1 = 9;
const int motor1Pin2 = 8;
const int motor2Pin1 = 7;
const int motor2Pin2 = 6;

// دبابيس التحكم في السرعة (Enable)
const int enableA = 10;
const int enableB = 5;

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  stopMotors(); 
  Serial.println("\n=== TESTING ULTRASONIC CAR ===");
}

void loop() {
  // تقليل السرعة قليلاً للمعمل ولتوفير الطاقة للحساس (150 بدلاً من 180)
  analogWrite(enableA, 150); 
  analogWrite(enableB, 150);
  
  // قراءة الحساس بدقة
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH, 30000); // إضافة timeout لمنع التهنيج
  distance = duration * 0.034 / 2;
  
  // طباعة المسافة -> افتح السيريال مونيطور وشوف الرقم كام!
  Serial.print("Measured Distance: "); 
  Serial.print(distance);
  Serial.println(" cm");

  // إذا كانت القراءة صفر أو خيالية نعتبر الطريق مفتوح
  if (distance <= 0 || distance > 400) {
    distance = 100; 
  }

  // اتخاذ القرار
  if (distance > 20) { // جعل مسافة الأمان 20 سم لتفادي القراءات الخاطئة
    moveForward();
  } else {
    // عائق حقيقي -> لف وتفادى
    stopMotors(); 
    delay(300);
    moveBackward(); 
    delay(400);
    turnRight(); 
    delay(400); // زيادة وقت اللف ليخرج تماماً من زاوية العائق
    stopMotors();
    delay(200);
  }
  
  delay(60); 
}

// دالات الحركة
void moveForward() {
  digitalWrite(motor1Pin1, LOW);  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH); digitalWrite(motor2Pin2, LOW);
}

void moveBackward() {
  digitalWrite(motor1Pin1, HIGH); digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);  digitalWrite(motor2Pin2, HIGH);
}

void turnLeft() {
  digitalWrite(motor1Pin1, LOW);  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);  digitalWrite(motor2Pin2, HIGH);
}

void turnRight() {
  digitalWrite(motor1Pin1, HIGH); digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH); digitalWrite(motor2Pin2, LOW);
}

void stopMotors() {
  digitalWrite(motor1Pin1, LOW);  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);  digitalWrite(motor2Pin2, LOW);
}
