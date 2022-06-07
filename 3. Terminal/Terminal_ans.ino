/******************************************************
 * 目標: 將序列埠控制LED燈的程式改成利用Dabble藍芽控制
 * 
 * 動作拆解:
 * 1. 引入Dabble函式庫
 * 2. 初始化藍芽溝通
 * 3. 接收藍芽資料
 * 4. 改為終端機模組
 ******************************************************/

#include <DabbleESP32.h>                 // 1. 引入Dabble函式庫

// 參數
#define LED_BULTIN 2
String data;

// 設定函式，只會執行一次
void setup(){
  pinMode(LED_BULTIN, OUTPUT);
  Dabble.begin("Bluetooth_Name");        // 2. 初始化藍芽溝通
}

// 迴圈函式，會不斷重複執行
void loop(){
  Dabble.processInput();                 // 3. 接收藍芽資料
  if(Terminal.available() > 0){          // 4. Serial 改為 Terminal
    data = Terminal.readString();        // 4. Serial 改為 Terminal
    data.trim();
    if(data == "On"){
      digitalWrite(LED_BULTIN, HIGH);
      Terminal.println("Lights on.");    // 4. Serial 改為 Terminal
    }
    if(data == "Off"){
      digitalWrite(LED_BULTIN, LOW);
      Terminal.println("Lights off.");   // 4. Serial 改為 Terminal
    }
  }
}