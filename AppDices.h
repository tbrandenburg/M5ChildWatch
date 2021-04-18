// AppDices.h
#ifndef APPDICES_H
#define APPDICES_H

#include "App.h"

#include <M5StickC.h>

#define DOT_SIZE 6
int dot[6][6][2] {
  {{35,35}},
  {{15,15},{55,55}},
  {{15,15},{35,35},{55,55}},
  {{15,15},{15,55},{55,15},{55,55}},
  {{15,15},{15,55},{35,35},{55,15},{55,55}},
  {{15,15},{15,35},{15,55},{55,15},{55,35},{55,55}},
  };

class AppDices : public App {
    private:
        void draw_dice(int16_t x, int16_t y, int n) {
        
            M5.Lcd.fillRect(x, y, 70, 70, WHITE);
          
            for(int d = 0; d < 6; d++) {
                if (dot[n][d][0] > 0) {
                    M5.Lcd.fillCircle(x+dot[n][d][0], y+dot[n][d][1], DOT_SIZE, TFT_BLACK);
                }
            }
        }    

    public:
        /* Inherit constructors */
        using App::App;

        void init() {
            M5.IMU.Init();
          
            M5.Lcd.setRotation(3);
            
            M5.Lcd.fillScreen(GREEN);
            
            M5.Lcd.setTextColor(BLACK);  // Adding a background colour erases previous text automatically
            M5.Lcd.setTextSize(1);
          
            M5.Lcd.setCursor(5, 30);  
            M5.Lcd.print("WACKEL MICH!");
        }

        void exec() {
            float accX = 0;
            float accY = 0;
            float accZ = 0;

            M5.IMU.getAccelData(&accX,&accY,&accZ);

            if (accX > 1.0 ||  accY > 1.0 ) {
        
                M5.Lcd.fillScreen(TFT_GREEN);
              
                // Draw first dice
                delay(500);  // A little delay to increase suspense :-D
                int number = random(0, 6);
                draw_dice(5,5,number);
              
                // Draw second dice
                delay(500);
                number = random(0, 6);
                draw_dice(85,5,number);
            }
        }
};

#endif