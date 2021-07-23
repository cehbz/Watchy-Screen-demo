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
#include "SyncTimeScreen.h"
#include "TimeScreen.h"
#include "UpdatefWScreen.h"
#include "Watchy.h"
#include "WeatherScreen.h"
#include "WifiScreen.h"

SetTimeScreen setTimeScreen;
SetupWifiScreen setupWifiScreen;
UpdateFWScreen updateFWScreen;
SyncTimeScreen syncTimeScreen;

MenuItem menu[] = {{"Set Time", &setTimeScreen},
                   {"Setup WiFi", &setupWifiScreen},
                   {"Update Firmware", &updateFWScreen},
                   {"Sync Time", &syncTimeScreen}};

MenuScreen menuScreen(menu, sizeof(menu) / sizeof(menu[0]));

TimeScreen timeScreen;
WeatherScreen weatherScreen;
BatteryScreen batteryScreen;
StepsScreen stepsScreen;
OrientationScreen orientationScreen;
BluetoothScreen bluetoothScreen;
WifiScreen wifiScreen;
SettingsScreen settingsScreen;
ShowBatteryScreen showBatteryScreen;
ShowBluetoothScreen showBluetoothScreen;
ShowOrientationScreen showOrientationScreen;
ShowStepsScreen showStepsScreen;
ShowWifiScreen showWifiScreen;

CarouselItem carousel[] = {{&timeScreen, nullptr},
                           {&weatherScreen, nullptr},
                           {&batteryScreen, &showBatteryScreen},
                           {&stepsScreen, &showStepsScreen},
                           {&orientationScreen, &showOrientationScreen},
                           {&bluetoothScreen, &showBluetoothScreen},
                           {&wifiScreen, &showWifiScreen},
                           {&settingsScreen, &menuScreen}};

CarouselScreen carouselScreen(carousel, sizeof(carousel) / sizeof(carousel[0]));

void setup() {
  Serial.begin(115200);
  DEBUG("%ld: setup %d\n", millis(), esp_sleep_get_wakeup_cause());

  Watchy::defaultScreen = &carouselScreen;
  Watchy::init();
}

void loop() {}  // this should never run, Watchy deep sleeps after init();