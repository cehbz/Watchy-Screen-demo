#include "BluetoothScreen.h"

#include "OptimaLTStd12pt7b.h"
#include "Watchy.h"

void BluetoothScreen::show() {
  Watchy::display.setFont(&OptimaLTStd12pt7b);
  Watchy::display.setCursor(0, 0);
  Watchy::display.printf("\nBluetooth\n");
}
void BluetoothScreen::up() { Watchy::setScreen(Watchy::defaultScreen); }
void BluetoothScreen::down() { Watchy::setScreen(Watchy::defaultScreen); }

BluetoothScreen bluetoothScreen;