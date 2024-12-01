// Khai báo chân kết nối cảm biến siêu âm SR04 và còi báo động
const int trigPin = 10;  // Chân Trig của SR04
const int echoPin = 9; // Chân Echo của SR04
const int buzzerPin = 5; // Chân kết nối với còi báo động

// Khai báo biến
long duration;
int distance;

void setup() {
  // Khai báo chân làm OUTPUT hoặc INPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Bật cổng Serial để hiển thị dữ liệu trên Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Gửi xung siêu âm từ cảm biến
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Đo thời gian từ lúc gửi xung đến khi nhận được xung phản xạ
  duration = pulseIn(echoPin, HIGH);
  
  // Chuyển thời gian thành khoảng cách (đơn vị: cm)
  distance = duration * 0.034 / 2;
  
  // Hiển thị khoảng cách lên Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  
  // Kiểm tra nếu khoảng cách dưới 1.5m thì kích hoạt còi báo động
  if (distance < 150 && distance > 0) {
    digitalWrite(buzzerPin, HIGH); // Bật còi
  } else {
    digitalWrite(buzzerPin, LOW); // Tắt còi
  }
  
  // Chờ một khoảng thời gian trước khi đo lại (có thể điều chỉnh)
  delay(100);
}
