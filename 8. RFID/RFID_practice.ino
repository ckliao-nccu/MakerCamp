// 引入函式庫
#include <SPI.h>
#include <MFRC522.h>

// 參數
#define LED_BUILTIN     2
#define RST_PIN         15          
#define SDA_PIN         21

byte uid[]={0x80, 0x3A, 0xFD, 0x22};  //許可的卡號
bool pass = true;

// MFRC522模組連線設定
MFRC522 mfrc522(SDA_PIN, RST_PIN); 

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
    pass = true;
    MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
    Serial.print(F("PICC type: "));
    Serial.println(mfrc522.PICC_GetTypeName(piccType));
    Serial.print(F("Card UID: "));
    // 印出卡片ID
    for (int i = 0; i < mfrc522.uid.size; i++) {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      if(mfrc522.uid.uidByte[i] != uid[i]){
        pass = false;
      }
    }
    // 卡片ID符合才會印出pass並亮燈
    Serial.println();
    if(pass){
      Serial.println("Pass");
      digitalWrite(LED_BUILTIN, HIGH);
    } else {
      Serial.println("Denied");
      digitalWrite(LED_BUILTIN, LOW);
    }
    // 暫停RFID模組，避免一瞬間不斷重複讀取同一張卡片
    mfrc522.PICC_HaltA(); 
    mfrc522.PCD_StopCrypto1();
  }
}
