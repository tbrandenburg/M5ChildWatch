// AppWatch.h
#ifndef APPWATCH_H
#define APPWATCH_H

#include "App.h"

#include <M5StickC.h>

class AppWatch : public App {
    private:
        RTC_TimeTypeDef RTC_TimeStruct;
    public:
        /* Inherit constructors */
        using App::App;

        void init() {
            M5.Lcd.setRotation(3);
            M5.Lcd.fillScreen(BLACK);
            
            M5.Lcd.setTextSize(1);
            M5.Lcd.setCursor(40, 0, 2);
            M5.Lcd.println("FELIX UHR :)");
        }
        void exec() {
            M5.Rtc.GetTime(&this->RTC_TimeStruct);
            M5.Lcd.setCursor(0, 25);

            M5.Lcd.setTextSize(2);
            M5.Lcd.printf("%02d : %02d : %02d\n",RTC_TimeStruct.Hours, RTC_TimeStruct.Minutes, RTC_TimeStruct.Seconds);

            delay(100);
        }
};

#endif