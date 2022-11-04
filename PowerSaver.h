// PowerSaver.h
#ifndef POWERSAVER_H
#define POWERSAVER_H

#include <M5StickC.h>

// The current implementation is quite inaccurate till
// it just checks the passed time looking on the minutes!
#define MAX_NO_ACTIVITY_MINUTES 2u

#define MIN_OP_BAT_VOLTAGE 3.5f

class PowerSaver {
    private:
        RTC_TimeTypeDef lastActivityTime;
        RTC_TimeTypeDef curTime;

        void printBatteryLow() {
            M5.Lcd.setRotation(3);
            
            M5.Lcd.fillScreen(BLACK);
            
            M5.Lcd.setTextSize(1);
            M5.Lcd.setTextColor(WHITE, BLACK);
            M5.Lcd.setCursor(10, 28);

            M5.Lcd.printf("Batterie leer :(");
        }
    public:
        PowerSaver()
        {
        }

        void init() {
            M5.Rtc.GetTime(&this->lastActivityTime);

            M5.Axp.EnableCoulombcounter();
        }

        // Call to trigger new activity at device
        void triggerActivity() {
            M5.Rtc.GetTime(&this->lastActivityTime);
        }

        // Check if power saving mode can be entered
        void check() {
            // Time check
            M5.Rtc.GetTime(&this->curTime);
            if(this->curTime.Minutes<this->lastActivityTime.Minutes) {
                // Handle minute overflow
                if( ( ( this->curTime.Minutes + 60u ) - this->lastActivityTime.Minutes ) >= MAX_NO_ACTIVITY_MINUTES) {
                    M5.Axp.DeepSleep(0);
                }
            } else {
                if( ( this->curTime.Minutes - this->lastActivityTime.Minutes ) >= MAX_NO_ACTIVITY_MINUTES) {
                    M5.Axp.DeepSleep(0);
                }
            }

            // Battery check
            if(M5.Axp.GetBatVoltage()<MIN_OP_BAT_VOLTAGE) {
                this->printBatteryLow();
                delay(5000);
                M5.Axp.PowerOff();
            }
        }
};

#endif