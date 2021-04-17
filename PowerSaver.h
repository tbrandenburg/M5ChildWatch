// PowerSaver.h
#ifndef POWERSAVER_H
#define POWERSAVER_H

#include <M5StickC.h>

// The current implementation is quite inaccurate till
// it just checks the passed time looking on the minutes!
#define MAX_NO_ACTIVITY_MINUTES 2u

class PowerSaver {
    private:
        RTC_TimeTypeDef lastActivityTime;
        RTC_TimeTypeDef curTime;
    public:
        PowerSaver()
        {
        }

        void init() {
            M5.Rtc.GetTime(&this->lastActivityTime);
        }

        // Call to trigger new activity at device
        void triggerActivity() {
            M5.Rtc.GetTime(&this->lastActivityTime);
        }

        // Check if power saving mode can be entered
        void check() {
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
        }
};

#endif