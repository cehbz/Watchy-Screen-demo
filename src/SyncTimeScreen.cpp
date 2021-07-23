#include "SyncTimeScreen.h"

#include <Wifi.h>

#include "Adafruit_GFX.h"
#include "OptimaLTStd12pt7b.h"
#include "Watchy.h"
#include "icons.h"
#include "time.h"

/*
void SyncTimeScreen::show() {
  constexpr char *label = "settings";
  const uint16_t fgColor = (bgColor == GxEPD_WHITE ? GxEPD_BLACK : GxEPD_WHITE);
  Watchy::display.setFont(&OptimaLTStd22pt7b);
  int16_t x1, y1;
  uint16_t w, h;
  Watchy::display.drawBitmap((200 - 96) / 2, (200 - 96) / 2 / 2,
                             bitmap_settings, 96, 96, fgColor);
  Watchy::display.getTextBounds(label, 0, 0, &x1, &y1, &w, &h);
  Watchy::display.setCursor((200 - w) / 2, 170);
  Watchy::display.print(label);
}
*/

void SyncTimeScreen::show() {
  Watchy::display.setFont(&OptimaLTStd12pt7b);
  Watchy::display.setCursor(0, 0);

  if (!Watchy::connectWiFi()) {
    Watchy::display.print("\n\nconnect wifi failed");
    return;
  }
  const char *tz = "AEST-10AEDT,M10.1.0,M4.1.0/3";  // Australia/Melbourne
  const char *ntpServer = "pool.ntp.org";
  configTzTime(tz, ntpServer);
  struct tm t;
  if (!getLocalTime(&t)) {
    Watchy::display.print("\n\ntime sync failed");
    return;
  }
  Watchy::display.print(&t, "\n\ntime synced\n%A %B %d %Y\n%H:%M:%S");
}