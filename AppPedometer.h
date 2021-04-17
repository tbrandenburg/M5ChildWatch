// AppPedometer.h
#ifndef APPPEDOMETER_H
#define APPPEDOMETER_H

#include "App.h"

#include <M5StickC.h>

class AppPedometer : public App {
    private:
    
    public:
        /* Inherit constructors */
        using App::App;

        void init() {
            M5.Lcd.setRotation(3);
            M5.Lcd.fillScreen(BLACK);
            
            M5.Lcd.setTextColor(RED, BLACK);
            M5.Lcd.setTextSize(1);
            M5.Lcd.setCursor(0, 0, 2);
            M5.Lcd.println("Hier koennen wir noch");
            M5.Lcd.println("was lustiges");
            M5.Lcd.println("programmieren :D");
            M5.Lcd.setTextColor(WHITE, BLACK);
        }
        void exec() {
        }
};

#endif