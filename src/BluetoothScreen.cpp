#include "BluetoothScreen.h"

#include "BatteryScreen.h"
#include "OptimaLTStd12pt7b.h"
#include "OrientationScreen.h"
#include "ShowBluetoothScreen.h"
#include "Watchy.h"

void BluetoothScreen::show() {
  Watchy::display.setFont(&OptimaLTStd12pt7b);
  Watchy::display.setCursor(0, 0);
  Watchy::display.printf("\nbluetooth\n");
}