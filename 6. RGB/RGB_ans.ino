/************************************************************
 * 目標: 讓RBG燈閃爍不同的顏色
 * 
 * 動作拆解:
 * 1. 設定參數 (#define)
 * 2. 設定針腳模式 (pinMode)
 * 3. 數位輸出 (digitalWrite)
 * 4. 延遲 (delay)
 ************************************************************/
// 參數
#define R_Pin           33
#define G_Pin           32
#define B_Pin           25

// 設定函式，只會執行一次
void setup() {
    pinMode(R_Pin, OUTPUT);
    pinMode(G_Pin, OUTPUT);
    pinMode(B_Pin, OUTPUT);
}

// 迴圈函式，會不斷重複執行
void loop() {
    color(1, 0, 0);
    delay(500);
    color(0, 1, 0);
    delay(500);
    color(0, 0, 1);
    delay(500);
    color(1, 1, 0);
    delay(500);
    color(1, 0, 1);
    delay(500);
    color(0, 1, 1);
    delay(500);
}

// 顏色控制函數
void color(int red, int green, int blue){
    digitalWrite(R_Pin, red);   
    digitalWrite(G_Pin, green); 
    digitalWrite(B_Pin, blue); 
}