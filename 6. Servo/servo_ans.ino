/************************************************************
 * 目標: 使用Dabble中的Terminal模組控制馬達旋轉的角度
 * 
 * 動作拆解:
 * 1. 引用伺服馬達函式庫 (<Servo.h>)
 * 2. 定義伺服馬達針腳
 * 3. 定義伺服馬達名稱 (Servo servo_name;)
 * 4. 連接伺服馬達 (.attach())
 * 5. 寫入角度 (.write())
 ************************************************************/
// 引入函式庫
#include <Servo.h>
#include <DabbleESP32.h> 

// 參數
#define SERVO_PIN 12             //定義伺服馬達針腳
Servo my_servo;                        //定義伺服馬達名稱

// 設定函式，只會執行一次
void setup(){
  my_servo.attach(SERVO_PIN);          //連接伺服馬達
  Dabble.begin("Bluetooth_Name");
}

// 迴圈函式，會不斷重複執行
void loop(){
  Dabble.processInput();
  if(Terminal.available() > 0){       
    int angle = Terminal.readNumber();
    my_servo.write(angle);             //寫入角度給伺服馬達
    Terminal.println(angle);
  }
}