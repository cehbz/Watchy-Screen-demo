#include "WifiScreen.h"

#include "OptimaLTStd12pt7b.h"
#include "ShowWifiScreen.h"
#include "StepsScreen.h"
#include "Watchy.h"

void WifiScreen::show() {
  Watchy::display.setFont(&OptimaLTStd12pt7b);
  Watchy::display.setCursor(0, 0);
  Watchy::display.printf("\nwifi\n");
}