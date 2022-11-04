// AppPedometer.h
#ifndef APPPEDOMETER_H
#define APPPEDOMETER_H

#include "App.h"

#include <M5StickC.h>

#define ACC_LIMIT 1.0f

class AppPedometer : public App {
    private:
        uint32_t steps = 0;
        float oldAccX = 0.0f;
        float oldAccY = 0.0f;
        float oldAccZ = 0.0f;
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

            // Only count if old accelerations were below limit
            if ( ( this->oldAccX <= ACC_LIMIT && accX > ACC_LIMIT ) || ( this->oldAccY<= ACC_LIMIT && accY > ACC_LIMIT ) ) {
                steps++;
            
                M5.Lcd.fillScreen(WHITE);

                M5.Lcd.setTextSize(1);
                M5.Lcd.setCursor(5, 5);
                M5.Lcd.print("Schritte:");

                M5.Lcd.setTextSize(2);
                M5.Lcd.setCursor(5, 25);
                M5.Lcd.printf("%d",steps);
            }

            this->oldAccX = accX;
            this->oldAccY = accY;
            this->oldAccZ = accZ;
        }
};

#endif