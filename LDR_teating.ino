هل #include <SoftwareSerial.h>
#include <TinyGPSPlus.h>
// تحديد أطراف الـ SoftwareSerial (RX = 4, TX = 3)
SoftwareSerial gpsSerial(4, 3);

// إنشاء كائن من مكتبة TinyGPS++
TinyGPSPlus gps;

void setup() {
  Serial.begin(9600);
  // المعدل الافتراضي لشريحة GP-01 هو 9600 baud
  gpsSerial.begin(9600);
  
  Serial.println("جاري البحث عن إشارة الأقمار الصناعية...");
}

void loop() {
  // قراءة البيانات من وحدة GP-01
  while (gpsSerial.available() > 0) {
    if (gps.encode(gpsSerial.read())) {
      displayLocation();
    }
  }
}

void displayLocation() {
  if (gps.location.isValid()) {
    Serial.print("خط العرض (Lat): ");
    Serial.println(gps.location.lat(), 6);
    
    Serial.print("خط الطول (Lng): ");
    Serial.println(gps.location.lng(), 6);
    
    Serial.print("الارتفاع: ");
    Serial.print(gps.altitude.meters());
    Serial.println(" متر");
    
    Serial.println("--------------------------------");
  } else {
    Serial.println("جاري تحديد إحداثيات الموقع (Waiting for Satellite Lock)...");
  }
}
