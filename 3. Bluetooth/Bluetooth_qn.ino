/******************************************************
 * 目標: 將序列埠控制LED燈的程式改成利用Dabble藍芽控制
 * 
 * 動作拆解:
 * 1. 引入Dabble函式庫
 * 2. 初始化藍芽溝通
 * 3. 接收藍芽資料
 * 4. 改為終端機模組
 ******************************************************/

// 1. 引入Dabble函式庫

// 參數
#define LED_BULTIN 2
String data;

// 設定函式，只會執行一次
void setup(){
  pinMode(LED_BULTIN, OUTPUT);
  // 2. 初始化藍芽溝通
}

// 迴圈函式，會不斷重複執行
void loop(){
  // 3. 接收藍芽資料
  // 4. 改為終端機模組
  if(Serial.available() > 0){      
    data = Serial.readString();    
    data.trim();
    if(data == "On"){
      digitalWrite(LED_BULTIN, HIGH);
      Serial.println("Lights on.");
    }
    if(data == "Off"){
      digitalWrite(LED_BULTIN, LOW);
      Serial.println("Lights off.");
    }
  }
}