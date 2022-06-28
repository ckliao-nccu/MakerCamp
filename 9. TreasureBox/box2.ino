#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SERVO_PIN       12  //伺服馬達
#define RST_PIN         15  //RST
#define SS_PIN          21  //SDA
#define LED             2   //內建LED
#define DEBOUNCE_TIME   50  
#define R_Pin           33
#define G_Pin           32
#define B_Pin           25

Servo servo1;  //伺服馬達名稱
MFRC522 mfrc522(SS_PIN, RST_PIN);   //Defined pins to module RC522

int angle_engage = 30;
int angle_disengage = 0;
byte uid[]={0x80, 0x3A, 0xFD, 0x22};  //許可的卡號

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(R_Pin, OUTPUT);
    pinMode(G_Pin, OUTPUT);
    pinMode(B_Pin, OUTPUT);

    servo1.attach(SERVO_PIN);

    Serial.begin(9600); 

    SPI.begin();
    mfrc522.PCD_Init();  //初始化MFRC522卡
    Serial.print("Reader: ");
    mfrc522.PCD_DumpVersionToSerial();  //顯示讀卡設備的版本
    servo1.write(angle_disengage);
    color(255,255,0); //黃色亮
}

void loop() {
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
        //顯示卡片內容
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
                Serial.println();
                Serial.println("Denied");
                color(255,0,0); //紅色亮
                delay(3000);
                color(0,0,0); //關燈
                break;
            }
        }
        if(pass){
            servo1.attach(SERVO_PIN);
            Serial.println();
            Serial.println("Opening");
            color(255,255,0); //綠色亮  
            servo1.write(angle_engage);
            delay(10000);
            servo1.write(angle_disengage);
            servo1.detach();
        }
        mfrc522.PICC_HaltA();  // instructs the PICC when in the ACTIVE state to go to a "STOP" state
        mfrc522.PCD_StopCrypto1(); //"stop" the encryption of the PCD, it must be called after communication with authentication, otherwise new communications can not be initiated
    }
}

void color (unsigned char red, unsigned char green, unsigned char blue)  //顏色控制函數 
{    
        digitalWrite(R_Pin, red);   
        digitalWrite(G_Pin, green); 
        digitalWrite(B_Pin, blue); 
}
