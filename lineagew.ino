#include <ld3320.h>
#include "Keyboard.h"

VoiceRecognition Voice;                         //聲明一個語音辨識對象

void setup(){
    Serial.begin(9600);
    Keyboard.begin();
    Keyboard.releaseAll();
    
    Voice.init();                               //初始化VoiceRecognition模組   
    Voice.addCommand("Chao Shou Di Ren Gong Ji", 0);
    Voice.addCommand("Ti Li Bu Zu Liao", 1);
    Voice.addCommand("Syu Yao Geng Duo De Yao Shuei", 2);
    Voice.addCommand("Syu Yao Jheng Li Yi Sia Bei Bao", 3);
    Voice.start();//開始辨識
}

void loop() {
    switch(Voice.read()){
        case 0:
            Keyboard.press('3');
            delay(50);
            Keyboard.releaseAll();
            Serial.println("遭受敵人攻擊了");
        break;
        
        case 1:
            Keyboard.press('4');
            delay(50);
            Keyboard.releaseAll();
            Serial.println("體力不足了");
        break;
        
        case 2:
            Keyboard.press('4');
            delay(50);
            Keyboard.releaseAll();
            Serial.println("需要更多的藥水");
        break;  
        
        case 3:
            Keyboard.press('4');
            delay(50);
            Keyboard.releaseAll();
            Serial.println("需要整理一下背包");
        break;  

        default:
        break;
    }
}