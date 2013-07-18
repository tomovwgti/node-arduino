/*
  Jenkins Status

  フルカラーLEDの色を変える
 */

#define LED_RED    3
#define LED_BLUE   6
#define LED_GREEN  5

void setup() {
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  analogWrite(LED_RED, 255);
  analogWrite(LED_BLUE, 255);
  analogWrite(LED_GREEN, 255);
  
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) { // シリアル通信でデータが送られてくるまで待つ。
    char c = Serial.read(); // 一文字分データを取り出す。
    
    if (c == 'g') { // Jenkinsビルド開始
      Serial.println("START");
      analogWrite(LED_RED, 255);
      analogWrite(LED_BLUE, 0); // 青LEDを点灯
      analogWrite(LED_GREEN, 255);
    } else if (c == 'e') { // エラー
      Serial.println("ERROR");
      analogWrite(LED_RED, 0);  // 赤LEDを点灯
      analogWrite(LED_BLUE, 255);
      analogWrite(LED_GREEN, 255);
    } else if ( c == 's') { // 成功
      Serial.println("SUCCESS");
      analogWrite(LED_RED, 255);
      analogWrite(LED_BLUE, 255);
      analogWrite(LED_GREEN, 0);  // 緑LEDを点灯
    } else if (c =='r') { // 初期化
      Serial.println("RESET");
      analogWrite(LED_RED, 255);
      analogWrite(LED_BLUE, 255);
      analogWrite(LED_GREEN, 255);
    } else {
      Serial.println("etc...");
      analogWrite(LED_RED, 255);
      analogWrite(LED_BLUE, 255);
      analogWrite(LED_GREEN, 255);
    }
  }
  
  delay(1000);
}
