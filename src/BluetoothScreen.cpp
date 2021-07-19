#include "BluetoothScreen.h"

#include "BatteryScreen.h"
#include "OptimaLTStd12pt7b.h"
#include "OrientationScreen.h"
#include "Watchy.h"

void BluetoothScreen::show() {
  Watchy::display.setFont(&OptimaLTStd12pt7b);
  Watchy::display.setCursor(0, 0);
  Watchy::display.printf("\nbluetooth\n");
}
void BluetoothScreen::back() { Watchy::setScreen(Watchy::defaultScreen); }
void BluetoothScreen::up() { Watchy::setScreen(&batteryScreen); }
void BluetoothScreen::down() { Watchy::setScreen(&orientationScreen); }

BluetoothScreen bluetoothScreen;