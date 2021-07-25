#include "ShowWifiScreen.h"

#include "OptimaLTStd22pt7b.h"
#include "Watchy.h"
#include "WifiScreen.h"

void ShowWifiScreen::show() {
  Watchy::display.setFont(&OptimaLTStd22pt7b);
  Watchy::display.setCursor(0, 0);
  Watchy::display.printf("\nwifi\nis");
  if (!Watchy::WIFI_CONFIGURED) {
    Watchy::display.printf(" not");
  }
  Watchy::display.printf("\nconfigured\n");
}
