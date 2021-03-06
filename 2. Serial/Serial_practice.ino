/************************************
 * 透過輸入訊息至序列埠來控制內建LED燈
 * **********************************/

// 參數
#define LED_BUILTIN 2
String data;

// 設定函式，只會執行一次
void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}

// 迴圈函式，會不斷重複執行
void loop(){
  if(Serial.available() > 0){
    data = Serial.readString();
    data.trim();
    if(data == "On"){
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("Lights on.");
    }
    if(data == "Off"){
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("Lights off.");
    }
  }
}