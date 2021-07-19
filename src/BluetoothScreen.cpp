#include "BluetoothScreen.h"

#include "BatteryScreen.h"
#include "OptimaLTStd12pt7b.h"
#include "OrientationScreen.h"
#include "Watchy.h"

void BluetoothScreen::show() {
  Watchy::display.setFont(&OptimaLTStd12pt7b);
  Watchy::display.setCursor(0, 0);
  Watchy::display.printf("\nBluetooth\n");
}
void BluetoothScreen::up() { Watchy::setScreen(&batteryScreen); }
void BluetoothScreen::down() { Watchy::setScreen(&orientationScreen); }

BluetoothScreen bluetoothScreen;