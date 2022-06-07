// 引入Dabble函式庫
#include <DabbleESP32.h>

// 定義終端機模組標頭檔
#define CUSTOM_SETTINGS
#define INCLUDE_TERMINAL_MODULE

// 設定參數
#define LED_BULTIN 2

String data;

// 設定函式，只會執行一次
void setup(){
  pinMode(LED_BULTIN, OUTPUT);
  Dabble.begin("Bluetooth_Name");
  Serial.begin(115200);
}

// 主函式，會不斷重複執行
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
/****************************************
 * 序列埠方式
 * if(Serial.available() > 0){
 *   data = Serial.readString();
 *   data.trim();
 *   if(data == "On"){
 *     digitalWrite(LED_BULTIN, HIGH);
 *     Serial.println("Lights on.");
 *   }
 *   if(data == "Off"){
 *     digitalWrite(LED_BULTIN, LOW);
 *     Serial.println("Lights off.");
 *   }
 * }
 *****************************************/
}