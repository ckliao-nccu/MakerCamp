/************************************************************
 * 目標: 查找Dabble文件，使用Gamepad Module控制馬達前後左右旋轉
 * 網址: https://thestempedia.com/docs/dabble/game-pad-module/
 * 
 * 動作拆解:
 * 1. 引入Dabble函式庫
 * 2. 初始化藍芽溝通
 * 3. 接收藍芽資料
 * 4. 遙控器模組函式
 * 
 * 小提醒:
 * #總共有4根針腳控制兩顆馬達
 * #除了讓他轉，也要記得讓他停
 * #可以利用函式打包不同動作
 ************************************************************/
#include <DabbleESP32.h> 

// 參數
#define LED_BULTIN 2

// 設定函式，只會執行一次
void setup(){
  pinMode(LED_BULTIN, OUTPUT);
  Dabble.begin("Bluetooth_Name"); 
}

// 迴圈函式，會不斷重複執行
void loop(){
  Dabble.processInput();
}