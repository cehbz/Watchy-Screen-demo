#include "config.h"  // should be first

#include "SyncTimeScreen.h"

#include <Wifi.h>

#include "Adafruit_GFX.h"
#include "OptimaLTStd12pt7b.h"
#include "Watchy.h"
#include "icons.h"
#include "time.h"

void timeSyncCallback(struct timeval *tv) {
  DEBUG("\n*** timeSyncCallback %ld.%ld\n", tv->tv_sec, tv->tv_usec);
}

RTC_DATA_ATTR const char *SyncTimeScreen::tz = TZ;
RTC_DATA_ATTR const char *SyncTimeScreen::ntpServer = NTP_SERVER;
RTC_DATA_ATTR const char *syncMsg = nullptr;
RTC_DATA_ATTR char buf[200];

void SyncTimeScreen::show() {
  Watchy::display.setFont(&OptimaLTStd12pt7b);
  Watchy::display.setCursor(0, 0);
  Watchy::display.print("\n");
  if (syncMsg) {
    Watchy::display.print(syncMsg);
    return;
  }
  time_t tt;
  time(&tt);
  DEBUG("SyncTimeScreen::show time %ld\n", tt);
  sntp_set_time_sync_notification_cb(timeSyncCallback);
  syncMsg = "synchronizing with\nNTP server";
  Watchy::display.print(syncMsg);
  Watchy::display.display(true);
  Watchy::display.fillScreen(bgColor);
  Watchy::display.setCursor(0, 0);
  Watchy::display.print("\n");

  if (!Watchy::connectWiFi()) {
    syncMsg = "connect wifi failed\npress back to exit";
    Watchy::display.print(syncMsg);
    return;
  }
  configTzTime(tz, ntpServer);
  struct tm t;
  // logic from getLocalTime
  uint32_t start = millis();
  time_t now;
  while ((millis() - start) <= 5000) {
    time(&now);
    if (now < SECS_YR_2000) {
      delay(10);
      continue;
    }
    localtime_r(&now, &t); // uses TZ
    buf[0] = 0;
    if (strftime(buf, sizeof(buf),
                 "time synced\n%A\n%B %d %Y\n%H.%M.%S\npress back to exit",
                 &t)) {
      syncMsg = buf;
    } else {
      syncMsg = "time synced\npress back to exit";
    }
    DEBUG("time synced %04d-%02d-%02d %02d:%02d:%02d dst %d\n",
          t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min,
          t.tm_sec, t.tm_isdst);
    tmElements_t te;
    breakTime(now, te);
    Watchy::RTC.write(te);
    DEBUG(
        "SyncTimeScreen::show RTC.write (UTC)  %04d-%02d-%02d "
        "%02d:%02d:%02d\n",
        te.Year + 1970, te.Month, te.Day, te.Hour, te.Minute, te.Second);
    Watchy::display.print(syncMsg);
    return;
  }
  syncMsg = "time sync failed\npress back to exit";
  Watchy::display.print(syncMsg);
}

void SyncTimeScreen::back() { syncMsg = nullptr; Screen::back(); }

// RTC does not know about TZ
// so DST has to be in app code
// so RTC must store UTC
// RTC computes leap year so you want year to be correct
// according to how the RTC represents it