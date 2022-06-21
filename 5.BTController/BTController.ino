#include <DabbleESP32.h>               // 1. 引入Dabble函式庫

// 參數
#define LED_BUILTIN 2
#define MOTOR_R1 27                    // 右邊馬達的針腳
#define MOTOR_R2 26
#define MOTOR_L1 33                    // 左邊馬達的針腳
#define MOTOR_L2 32

// 設定函式，只會執行一次
void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(MOTOR_R1, OUTPUT);           // 馬達設為輸出模式
  pinMode(MOTOR_R2, OUTPUT);
  pinMode(MOTOR_L1, OUTPUT);
  pinMode(MOTOR_L2, OUTPUT);
  Dabble.begin("Bluetooth_Name");      // 2. 初始化藍芽溝通
}

// 迴圈函式，會不斷重複執行
void loop(){
  Dabble.processInput();               // 3. 接收藍芽資料
  if(GamePad.isUpPressed()){
    goAhead();
  } else if (GamePad.isDownPressed()){
    goBack();
  } else {
    goStop();
  }
}

// 前進函式
void goAhead(){
  analogWrite(MOTOR_R1, 0);
  analogWrite(MOTOR_R2, 200);
  analogWrite(MOTOR_L1, 0);
  analogWrite(MOTOR_L2, 200);
}

// 後退函式
void goBack(){
  analogWrite(MOTOR_R1, 200);
  analogWrite(MOTOR_R2, 0);
  analogWrite(MOTOR_L1, 200);
  analogWrite(MOTOR_L2, 0);
}

// 停止函式
void goStop(){
  analogWrite(MOTOR_R1, 0);
  analogWrite(MOTOR_R2, 0);
  analogWrite(MOTOR_L1, 0);
  analogWrite(MOTOR_L2, 0);
}