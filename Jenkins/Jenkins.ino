/*
  Jenkins Status

  フルカラーLEDの色を変える
 */

#define LED_RED    9
#define LED_BLUE  10
#define LED_GREEN 11

void setup() {
  pinMode(LED_RED, OUTPUT);     // 赤LED接続のピン(9番)をアナログ出力に設定
  pinMode(LED_BLUE, OUTPUT);     // 青LED接続のピン(10番)をアナログ出力に設定
  pinMode(LED_GREEN, OUTPUT);     // 緑LED接続のピン(11番)をアナログ出力に設定
  analogWrite(LED_RED, 0);
  analogWrite(LED_BLUE, 0);
  analogWrite(LED_GREEN, 0);
  
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) { // シリアル通信でデータが送られてくるまで待つ。
    char c = Serial.read(); // 一文字分データを取り出す。
    
    if (c == 'g') { // Jenkinsビルド開始
      Serial.println("START");
      analogWrite(LED_RED, 0);
      analogWrite(LED_BLUE, 1023); // 青LEDを点灯
      analogWrite(LED_GREEN, 0);
    } else if (c == 'e') { // エラー
      Serial.println("ERROR");
      analogWrite(LED_RED, 1023);  // 赤LEDを点灯
      analogWrite(LED_BLUE, 0);
      analogWrite(LED_GREEN, 0);
    } else if ( c == 's') { // 成功
      Serial.println("SUCCESS");
      analogWrite(LED_RED, 0);
      analogWrite(LED_BLUE, 0);
      analogWrite(LED_GREEN, 1023);  // 緑LEDを点灯
    } else if (c =='r') {
      Serial.println("RESET");
      analogWrite(LED_RED, 0);
      analogWrite(LED_BLUE, 0);
      analogWrite(LED_GREEN, 0);
    } else {
      Serial.println("RESET");
      analogWrite(LED_RED, 0);
      analogWrite(LED_BLUE, 1023);
      analogWrite(LED_GREEN, 1023);
    }
  }
  
  delay(1000);
}
