#include "BatteryScreen.h"

#include "OptimaLTStd12pt7b.h"
#include "Watchy.h"

void BatteryScreen::show() {
  Watchy::display.setFont(&OptimaLTStd12pt7b);
  Watchy::display.setCursor(0, 0);
  Watchy::display.printf("\nBattery\n");
}
void BatteryScreen::up() { Watchy::setScreen(Watchy::defaultScreen); }
void BatteryScreen::down() { Watchy::setScreen(Watchy::defaultScreen); }

BatteryScreen batteryScreen;