/************************************************************
 * 目標: 使用Gamepad Module控制馬達前後左右旋轉
 * 
 * 動作拆解:
 * 1. 加入左轉&右轉函式
 * 2. 控制何時左轉及右轉
 ************************************************************/
// 引入函式庫
#include <DabbleESP32.h>               // 1. 引入Dabble函式庫
#include <ESP32Servo.h>

// 參數
#define LED_BUILTIN 2
#define MOTOR_R1 27                    // 右邊馬達的針腳
#define MOTOR_R2 26
#define MOTOR_L1 33                    // 左邊馬達的針腳
#define MOTOR_L2 32
#define SERVOPIN_L 12
#define SERVOPIN_R 13
Servo servo_L;
Servo servo_R;

// 設定函式，只會執行一次
void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(MOTOR_R1, OUTPUT);           // 馬達設為輸出模式
  pinMode(MOTOR_R2, OUTPUT);
  pinMode(MOTOR_L1, OUTPUT);
  pinMode(MOTOR_L2, OUTPUT);
  servo_L.attach(SERVOPIN_L);
  servo_R.attach(SERVOPIN_R);
  Dabble.begin("Bluetooth_Name");      // 2. 初始化藍芽溝通
}

// 迴圈函式，會不斷重複執行
void loop(){
  Dabble.processInput();               // 3. 接收藍芽資料
  if(GamePad.isTrianglePressed()){
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
  if(GamePad.isCirclePressed()){
    servo_L.write(30);
    servo_L.write(0);
  }
  if(GamePad.isCrossPressed()){
    servo_R.write(30);
    servo_R.write(0);
  }
  int r = GamePad.getRadius();
  int x = static_cast<int>(GamePad.getXaxisData());
  int y = static_cast<int>(GamePad.getYaxisData());
  go(x, y, r);
}

// 方向控制函式
void go(int x, int y, int r){
  Serial.print(x);
  Serial.print(',');
  Serial.print(y);
  Serial.print(',');
  Serial.println(r);
  if(r==0 || (x==0 && y==0)){
    stop();
  } else {
    int speedFast = r * 25 + 80;
    int speedSlow = (r-abs(x)) * 25 + 80;
    bool f_b = (y>0) ? true : false;
    if(y==0){
      f_b = (x>0) ? true : false;
      speedSlow = 0;
    }
    if(x>0){
      L_wheel(f_b, speedFast);
      R_wheel(f_b, speedSlow);
    } else {
      L_wheel(f_b, speedSlow);
      R_wheel(f_b, speedFast);
    }
  }
}

// 停止函式
void stop(){
  Serial.println("Motor stopped");
  analogWrite(MOTOR_R1, 0);
  analogWrite(MOTOR_R2, 0);
  analogWrite(MOTOR_L1, 0);
  analogWrite(MOTOR_L2, 0);
}

// 控制右輪函式
void R_wheel(bool f_b, int speed){
  if (f_b){
    analogWrite(MOTOR_R2, 0);
    analogWrite(MOTOR_R1, speed);
  } else {
    analogWrite(MOTOR_R1, 0);
    analogWrite(MOTOR_R2, speed);
  }
}

// 控制左輪函式
void L_wheel(bool f_b, int speed){
  if (f_b){
    analogWrite(MOTOR_L1, 0);
    analogWrite(MOTOR_L2, speed);
  } else {
    analogWrite(MOTOR_L2, 0);
    analogWrite(MOTOR_L1, speed);
  }
}