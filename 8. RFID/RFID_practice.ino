// 引入函式庫
#include <SPI.h>
#include <MFRC522.h>

// 參數
#define LED_BUILTIN     2
#define RST_PIN         15          
#define SS_PIN          21  //就是模組上的SDA接腳
byte uid[]={0x80, 0x3A, 0xFD, 0x22};  //許可的卡號
//used in authentication
MFRC522::MIFARE_Key key;
//authentication return status code
MFRC522::StatusCode status;
// Defined pins to module RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); 


// 設定函式，只會執行一次
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); 
  SPI.begin();
  mfrc522.PCD_Init(); // 初始化MFRC522卡
  Serial.print(F("Reader "));
  Serial.print(F(": "));
  mfrc522.PCD_DumpVersionToSerial(); // 顯示讀卡設備的版本
}


// 迴圈函式，會不斷重複執行
void loop() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // 顯示卡片內容
    MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
    bool pass = true;
    Serial.print(F("PICC type: "));
    Serial.println(mfrc522.PICC_GetTypeName(piccType));  //顯示卡片的類型
    Serial.print(F("Card UID: "));
    for (int i = 0; i < mfrc522.uid.size; i++) {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      if(mfrc522.uid.uidByte[i] != uid[i]){
        pass = false;
      }
    }
    Serial.println();
    if(pass){
      Serial.println("Pass");
      digitalWrite(LED_BUILTIN, HIGH);
    } else {
      Serial.println("Denied");
      digitalWrite(LED_BUILTIN, LOW);
    }
    mfrc522.PICC_HaltA();  // instructs the PICC when in the ACTIVE state to go to a "STOP" state
    mfrc522.PCD_StopCrypto1(); //"stop" the encryption of the PCD, it must be called after communication with authentication, otherwise new communications can not be initiated
  }
}
