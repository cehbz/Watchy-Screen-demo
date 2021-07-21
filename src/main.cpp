#include "BatteryScreen.h"
#include "BluetoothScreen.h"
#include "CarouselScreen.h"
#include "MenuScreen.h"
#include "OrientationScreen.h"
#include "SetTimeScreen.h"
#include "SettingsScreen.h"
#include "SetupWifiScreen.h"
#include "ShowBatteryScreen.h"
#include "ShowBluetoothScreen.h"
#include "ShowOrientationScreen.h"
#include "ShowStepsScreen.h"
#include "ShowWifiScreen.h"
#include "StepsScreen.h"
#include "TimeScreen.h"
#include "UpdatefWScreen.h"
#include "Watchy.h"
#include "WeatherScreen.h"
#include "WifiScreen.h"

CarouselScreen carouselScreen;

MenuScreen menuScreen(&carouselScreen);

SetTimeScreen setTimeScreen(&menuScreen);
SetupWifiScreen setupWifiScreen(&menuScreen);
UpdateFWScreen updateFWScreen(&menuScreen);

MenuItem menu[] = {{"Set Time", &setTimeScreen},
                   {"Setup WiFi", &setupWifiScreen},
                   {"Update Firmware", &updateFWScreen}};


TimeScreen timeScreen(&carouselScreen);
WeatherScreen weatherScreen(&carouselScreen);
BatteryScreen batteryScreen(&carouselScreen);
StepsScreen stepsScreen(&carouselScreen);
OrientationScreen orientationScreen(&carouselScreen);
BluetoothScreen bluetoothScreen(&carouselScreen);
WifiScreen wifiScreen(&carouselScreen);
SettingsScreen settingsScreen(&carouselScreen);
ShowBatteryScreen showBatteryScreen(&carouselScreen);
ShowBluetoothScreen showBluetoothScreen(&carouselScreen);
ShowOrientationScreen showOrientationScreen(&carouselScreen);
ShowStepsScreen showStepsScreen(&carouselScreen);
ShowWifiScreen showWifiScreen(&carouselScreen);

CarouselItem carousel[] = {{&timeScreen, nullptr},
                           {&weatherScreen, nullptr},
                           {&batteryScreen, &showBatteryScreen},
                           {&stepsScreen, &showStepsScreen},
                           {&orientationScreen, &showOrientationScreen},
                           {&bluetoothScreen, &showBluetoothScreen},
                           {&wifiScreen, &showWifiScreen},
                           {&settingsScreen, &menuScreen}};


void setup() {
  Serial.begin(115200);
  DEBUG("  %ld: setup %d\n", millis(), esp_sleep_get_wakeup_cause());

  menuScreen.setItems(menu, sizeof(menu) / sizeof(menu[0]));
  carouselScreen.setItems(carousel, sizeof(carousel) / sizeof(carousel[0]));

  Watchy::defaultScreen = &carouselScreen;
  Watchy::init();
}

void loop() {}  // this should never run, Watchy deep sleeps after init();