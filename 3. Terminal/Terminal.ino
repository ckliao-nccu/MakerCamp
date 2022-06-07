// 引入Dabble函式庫
#include <DabbleESP32.h>

// 參數
#define LED_BULTIN 2
String data;

// 設定函式，只會執行一次
void setup(){
  pinMode(LED_BULTIN, OUTPUT);
  Dabble.begin("Bluetooth_Name");
}

// 迴圈函式，會不斷重複執行
void loop(){
  Dabble.processInput();
  if(Terminal.available() > 0){
    data = Terminal.readString();
    data.trim();
    if(data == "On"){
      digitalWrite(LED_BULTIN, HIGH);
      Terminal.println("Lights on.");
    }
    if(data == "Off"){
      digitalWrite(LED_BULTIN, LOW);
      Terminal.println("Lights off.");
    }
  }
}