#include "ShowBluetoothScreen.h"

#include "BluetoothScreen.h"
#include "OptimaLTStd22pt7b.h"
#include "Watchy.h"

void ShowBluetoothScreen::show() {
  Watchy::display.setFont(&OptimaLTStd22pt7b);
  Watchy::display.setCursor(0, 0);
  Watchy::display.printf("\nbluetooth\nis");
  if (!Watchy::BLE_CONFIGURED) {
    Watchy::display.printf(" not");
  }
  Watchy::display.printf("\nconfigured\n");
}
void ShowBluetoothScreen::back() { Watchy::setScreen(&bluetoothScreen); }

ShowBluetoothScreen showBluetoothScreen;