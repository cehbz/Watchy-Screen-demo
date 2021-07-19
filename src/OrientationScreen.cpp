#include "OrientationScreen.h"

#include "BluetoothScreen.h"
#include "OptimaLTStd12pt7b.h"
#include "SettingsScreen.h"
#include "Watchy.h"

void OrientationScreen::show() {
  Watchy::display.setFont(&OptimaLTStd12pt7b);
  Watchy::display.setCursor(0, 0);
  Watchy::display.printf("\norientation\n");
}
void OrientationScreen::back() { Watchy::setScreen(Watchy::defaultScreen); }
void OrientationScreen::up() { Watchy::setScreen(&bluetoothScreen); }
void OrientationScreen::down() { Watchy::setScreen(&settingsScreen); }

OrientationScreen orientationScreen;