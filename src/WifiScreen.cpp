#include "WifiScreen.h"

#include "OptimaLTStd12pt7b.h"
#include "Watchy.h"

void WifiScreen::show() {
  Watchy::display.setFont(&OptimaLTStd12pt7b);
  Watchy::display.setCursor(0, 0);
  Watchy::display.printf("\nWifi\n");
}
void WifiScreen::up() { Watchy::setScreen(Watchy::defaultScreen); }
void WifiScreen::down() { Watchy::setScreen(Watchy::defaultScreen); }

WifiScreen wifiScreen;