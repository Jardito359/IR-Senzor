#include <M5StickCPlus.h>
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>

uint8_t sAddress = 0x8;
uint8_t sCommand = 0xA;
uint8_t sRepeats = 1;

void setup(){
    M5.begin();
    Serial.begin(115200);
    M5.Lcd.setTextFont(1);
    M5.Lcd.setTextSize(2);
    M5.Lcd.setTextColor(WHITE);

}

void loop(){

    sCommand = 0xA;
    M5.update();
    IrSender.sendNEC(sAddress, sCommand, sRepeats);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(5,50);
    M5.Lcd.print(sCommand, HEX);
    M5.Lcd.setCursor(10,0);
    M5.Lcd.println("poslano");
    Serial.print("poslano ");
    delay(2000);
        
        

}

