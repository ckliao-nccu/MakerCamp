/***************************
 * 讓針腳2的LED燈每隔一秒閃爍
 ***************************/

// 設定針腳編號
int led = 2;

// 設定函式，只會執行一次
void setup() {
  // 將led針腳初始化為輸出模式
  pinMode(led, OUTPUT);
}

// 主函式，會不斷重複執行
void loop() {
  digitalWrite(led, HIGH);   // 輸出高電位的訊號到led針腳
  delay(1000);               // 暫停程式執行一秒鐘
  digitalWrite(led, LOW);    // 輸出低電位的訊號到led針腳
  delay(1000);               // 暫停程式執行一秒鐘
}

