/*****************
* 目標: 在內建LED燈亮時印出"LED on."的字樣，在LED燈熄滅時印出"LED off."的字樣
*
* 動作拆解:
* 1. 啟動序列埠通訊
* 2. 序列埠印出字串並換行
*****************/

// 設定接腳編號
#define LED_BULTIN 2

// 設定函式，只會執行一次
void setup() {
  // 1. 啟動序列埠通訊
  pinMode(LED_BULTIN, OUTPUT);
}

// 迴圈函式，會不斷重複執行
void loop() {
  // 2. 序列埠印出字串並換行
  digitalWrite(LED_BULTIN, HIGH);   // 輸出高電位的訊號到led接腳
  delay(1000);               // 暫停程式執行一秒鐘
  digitalWrite(LED_BULTIN, LOW);    // 輸出低電位的訊號到led接腳
  delay(1000);               // 暫停程式執行一秒鐘
}

