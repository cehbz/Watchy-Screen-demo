#include "BatteryScreen.h"

#include "BluetoothScreen.h"
#include "OptimaLTStd12pt7b.h"
#include "ShowBatteryScreen.h"
#include "Watchy.h"
#include "WeatherScreen.h"

void BatteryScreen::show() {
  Watchy::display.setFont(&OptimaLTStd12pt7b);
  Watchy::display.setCursor(0, 0);
  Watchy::display.printf("\nbattery\n");
}