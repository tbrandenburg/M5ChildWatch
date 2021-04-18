#include <M5StickC.h>
#include <AppCtrl.h>
#include "AppWatch.h"
#include "AppAddress.h"
#include "AppPedometer.h"
#include "AppDices.h"
#include "AppBattery.h"
#include "PowerSaver.h"

AppCtrl appCtrl = AppCtrl();

AppWatch myWatch = AppWatch(&appCtrl);
AppPedometer myPedometer = AppPedometer(&appCtrl);
AppDices myDices = AppDices(&appCtrl);
AppBattery myBattery = AppBattery(&appCtrl);
AppAddress myAddress = AppAddress(&appCtrl);

PowerSaver pwrSaver = PowerSaver();

// the setup routine runs once when M5StickC starts up
void setup(){
  M5.begin();

  // Apps
  appCtrl.addApp(&myWatch);
  appCtrl.addApp(&myPedometer);
  appCtrl.addApp(&myDices);
  appCtrl.addApp(&myBattery);
  appCtrl.addApp(&myAddress);

  appCtrl.start();

  // Init power saver
  pwrSaver.init();
}

// the loop routine runs over and over again forever
void loop() {
    appCtrl.exec();

    // Read buttons before evaluating their state
    M5.update();

    // Switch to next app if button A (M5) was pressed
    if(M5.BtnA.wasPressed()) {
      appCtrl.nextApp();
      pwrSaver.triggerActivity();
    }

    // Go to deep sleep if button B was pressed
    if(M5.BtnB.wasPressed()) {
        // Power off ESP32
        M5.Axp.DeepSleep(0);
    }

    // Check if power saving can be entered
    pwrSaver.check();
}
