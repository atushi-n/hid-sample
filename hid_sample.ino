#include "ConsumerControl.h"

u8 previousButtonState = 1;  // 連打防止フラグ

void setup() {
  pinMode(7, INPUT_PULLUP);  // 音量大にするピン7
  pinMode(8, INPUT_PULLUP);  // 音量小にするピン8
  pinMode(9, INPUT_PULLUP);  // 音量消音にするピン9
}

void loop() {
  if(digitalRead(7)==LOW){
    Serial.println("abc");
    ConsumerControl.press(VOLUME_UP); // 音量大ボタンを押す
    ConsumerControl.release(); // ボタンを離す
    delay(100);

  } else if(digitalRead(8)==LOW){
    ConsumerControl.press(VOLUME_DOWN); // 音量小ボタンを押す
    ConsumerControl.release(); // ボタンを離す
    delay(100);

  } else if(digitalRead(9)==LOW){
    if(previousButtonState==0){
      ConsumerControl.press(VOLUME_MUTE);  // 音量消音ボタンを押す
      previousButtonState = 1;

    } else {
      ConsumerControl.release(); // ボタンを離す
      previousButtonState = 1;
    }
  }else {
    if(previousButtonState==1){
      ConsumerControl.release(); // ボタンを離す
      previousButtonState = 0;
    }
  }
}
