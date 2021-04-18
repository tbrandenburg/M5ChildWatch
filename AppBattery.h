// AppBattery.h
#ifndef APPBATTERY_H
#define APPBATTERY_H

#include "App.h"

#include <M5StickC.h>

#include <AXP192.h>

TFT_eSprite tftSprite = TFT_eSprite(&M5.Lcd); 

class AppBattery : public App {
    private:
    
    public:
        /* Inherit constructors */
        using App::App;

        void init() {
            M5.Lcd.setRotation(3);
            
            M5.Lcd.fillScreen(BLACK);
            
            M5.Lcd.setTextSize(1);
            M5.Lcd.setTextColor(WHITE, BLACK);

            tftSprite.createSprite(160, 80);
            tftSprite.setRotation(3);

            M5.Axp.EnableCoulombcounter();
        }

        void exec() {
            tftSprite.fillSprite(BLACK);
            tftSprite.setCursor(0, 0, 1);
            tftSprite.printf("AXP Temp: %.1fC \r\n", M5.Axp.GetTempInAXP192());
            tftSprite.setCursor(0, 10);
            tftSprite.printf("Bat:\r\n  V: %.3fv  I: %.3fma\r\n", M5.Axp.GetBatVoltage(), M5.Axp.GetBatCurrent());
            tftSprite.setCursor(0, 30);  
            tftSprite.printf("USB:\r\n  V: %.3fv  I: %.3fma\r\n", M5.Axp.GetVBusVoltage(), M5.Axp.GetVBusCurrent());
            tftSprite.setCursor(0, 50);    
            tftSprite.printf("5V-In:\r\n  V: %.3fv  I: %.3fma\r\n", M5.Axp.GetVinVoltage(), M5.Axp.GetVinCurrent());
            tftSprite.setCursor(0, 70);    
            tftSprite.printf("Bat power %.3fmw", M5.Axp.GetBatPower());
            tftSprite.pushSprite(0, 0);
            delay(100);
        }
};

#endif