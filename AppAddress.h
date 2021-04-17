// AppAddress.h
#ifndef APPADDRESS_H
#define APPADDRESS_H

#include "App.h"

#include <M5StickC.h>

class AppAddress : public App {
    private:
    
    public:
        /* Inherit constructors */
        using App::App;

        void init() {
            M5.Lcd.setRotation(3);
            M5.Lcd.fillScreen(BLACK);
            
            M5.Lcd.setTextSize(1);
            M5.Lcd.setCursor(0, 0, 2);
            M5.Lcd.println("Adresse:");
            M5.Lcd.println("Felix Brandenburg");
            M5.Lcd.println("Rathausweg 9");
            M5.Lcd.println("71679 Asperg");
        }
        void exec() {
        }
};

#endif