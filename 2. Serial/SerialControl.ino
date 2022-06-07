/************************************
 * 透過輸入訊息至序列埠來控制內建LED燈
 * **********************************/

// 設定參數
int led = 2;
String data;

// 設定函式，只會執行一次
void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(115200);
}

// 主函式，會不斷重複執行
void loop(){
  if(Serial.available() > 0){
    data = Serial.readString();
    data.trim();
    if(data = "On"){
      digitalWrite(led, HIGH);
      Serial.println("Lights on.");
    }
    if(data = "Off"){
      digitalWrite(led, Low);
      Serial.println("Lights off.");
    }
  }
}