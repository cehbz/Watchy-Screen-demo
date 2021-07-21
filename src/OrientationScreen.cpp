#include "OrientationScreen.h"

#include "BluetoothScreen.h"
#include "OptimaLTStd12pt7b.h"
#include "SettingsScreen.h"
#include "ShowOrientationScreen.h"
#include "Watchy.h"

void OrientationScreen::show() {
  Watchy::display.setFont(&OptimaLTStd12pt7b);
  Watchy::display.setCursor(0, 0);
  Watchy::display.printf("\norientation\n");
}