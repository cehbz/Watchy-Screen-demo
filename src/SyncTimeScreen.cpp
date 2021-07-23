#include "SyncTimeScreen.h"

#include <Wifi.h>

#include "Adafruit_GFX.h"
#include "OptimaLTStd12pt7b.h"
#include "Watchy.h"
#include "icons.h"
#include "time.h"

void SyncTimeScreen::show() {
  Watchy::display.setFont(&OptimaLTStd12pt7b);
  Watchy::display.setCursor(0, 0);
  Watchy::display.println();
  time_t tt;
  time(&tt);
  DEBUG("SyncTimeScreen::show time %ld\n", tt);

  if (!Watchy::connectWiFi()) {
    Watchy::display.print("\nconnect wifi failed");
    return;
  }
  const char *tz = "AEST-10AEDT,M10.1.0,M4.1.0/3";  // Australia/Melbourne
  const char *ntpServer = "pool.ntp.org";
  configTzTime(tz, ntpServer);
  setenv("TZ", tz, true);
  struct tm t;
  if (!getLocalTime(&t)) {
    Watchy::display.print("\ntime sync failed");
    return;
  }
  Watchy::display.print(&t, "\ntime synced\n%A %B %d %Y\n%H.%M.%S");
  DEBUG("SyncTimeScreen::show getLocalTime ");
#ifdef DEBUGPORT
  DEBUGPORT.print(&t, "%A %B %d %Y\n%H.%M.%S\n");
#endif

  time(&tt);
  DEBUG("SyncTimeScreen::show RTC.set %ld\n", tt);
  Watchy::RTC.set(tt);
  struct tm *tp = localtime(&tt);
  DEBUG("SyncTimeScreen::show localtime ");
#ifdef DEBUGPORT
  DEBUGPORT.print(tp, "%A %B %d %Y\n%H.%M.%S\n");
#endif
}