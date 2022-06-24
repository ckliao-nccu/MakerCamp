// 右邊馬達的針腳
#define MOTOR_R1 27
#define MOTOR_R2 26

// 設定函式，只會執行一次
void setup() {
  // 馬達設為輸出模式
  pinMode(MOTOR_R1, OUTPUT);
  pinMode(MOTOR_R2, OUTPUT);
}

// 迴圈函式，會不斷重複執行
void loop() {
  // 馬達正轉3秒
  analogWrite(MOTOR_R1, 0);
  analogWrite(MOTOR_R2, 180);
  delay(3000);
  // 馬達停止1秒
  analogWrite(MOTOR_R1, 0);
  analogWrite(MOTOR_R2, 0);
  delay(1000);
  // 馬達反轉3秒
  analogWrite(MOTOR_R1, 180);
  analogWrite(MOTOR_R2, 0);
  delay(3000);
  // 馬達停止1秒
  analogWrite(MOTOR_R1, 0);
  analogWrite(MOTOR_R2, 0);
  delay(1000);
}
