// AppPedometer.h
#ifndef APPPEDOMETER_H
#define APPPEDOMETER_H

#include "App.h"

#include <M5StickC.h>

class AppPedometer : public App {
    private:
        uint32_t steps = 0;
    public:
        /* Inherit constructors */
        using App::App;

        void init() {
            M5.IMU.Init();
          
            M5.Lcd.setRotation(3);
            
            M5.Lcd.fillScreen(WHITE);
            
            M5.Lcd.setTextColor(BLACK, WHITE);  // Adding a background colour erases previous text automatically
            M5.Lcd.setTextSize(1);
          
            M5.Lcd.setCursor(5, 30);  
            M5.Lcd.print("BEWEGE DICH!");
        }

        void exec() {
            float accX = 0;
            float accY = 0;
            float accZ = 0;

            M5.IMU.getAccelData(&accX,&accY,&accZ);

            if (accX > 1.0 ||  accY > 1.0 ) {
                steps++;
            
                M5.Lcd.fillScreen(WHITE);

                M5.Lcd.setTextSize(1);
                M5.Lcd.setCursor(5, 5);
                M5.Lcd.print("Schritte:");

                M5.Lcd.setTextSize(2);
                M5.Lcd.setCursor(5, 25);
                M5.Lcd.printf("%d",steps);

                delay(200);
            }
        }
};

#endif