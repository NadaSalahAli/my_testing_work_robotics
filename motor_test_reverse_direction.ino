// Motor A (اليمين - المتصل بـ OUT1 و OUT2)
#define ENA 5   
#define IN1 8   
#define IN2 4   // تم التغيير إلى دبوس 4 السليم

// Motor B (الشمال - المتصل بـ OUT3 و OUT4)
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
  // 1. الموتورين للأمام
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 200); 
  analogWrite(ENB, 200); 
  delay(3000); 

  // 2. توقف
  analogWrite(ENA, 0); 
  analogWrite(ENB, 0); 
  delay(2000); 

  // 3. الموتورين للخلف معاً
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH); // الإشارة ستخرج من دبوس 4 السليم
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, 200); 
  analogWrite(ENB, 200); 
  delay(3000); 

  // 4. توقف
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  delay(2000); 
}
