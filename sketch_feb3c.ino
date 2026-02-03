// --- 完整超音波測試程式碼 ---
// 硬體接線：Trig 接 P13, Echo 接 P12

const int trigPin = 13;
const int echoPin = 12;

// 定義變數儲存時間與距離
long duration;
int distance;

void setup() {
  // 設定序列埠通訊頻率，ESP32 常用 115200
  Serial.begin(115200); 
  
  // 設定腳位模式
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  
  Serial.println("ESP32 超音波感測器測試開始...");
}

void loop() {
  // 1. 讓 Trig 腳位先送出低電位，確保訊號乾淨
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // 2. 觸發感測器：送出 10 微秒的高電位訊號
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 3. 讀取 Echo 腳位回傳的高電位持續時間 (單位：微秒)
  duration = pulseIn(echoPin, HIGH);

  // 4. 計算距離 (音速 0.034 cm/us，來回需除以 2)
  distance = duration * 0.034 / 2;

  // 5. 輸出結果到監控器
  if (distance > 400 || distance <= 0) {
    Serial.println("偵測失敗或超出範圍");
  } else {
    Serial.print("距離: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  // 延遲 500 毫秒再測下一次
  delay(500);
}