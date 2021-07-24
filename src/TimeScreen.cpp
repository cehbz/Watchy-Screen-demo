#include "TimeScreen.h"

#include "OptimaLTStd22pt7b.h"
#include "OptimaLTStd7pt7b.h"
#include "OptimaLTStd_Bold22pt7b.h"
#include "SyncTimeScreen.h"

using namespace Watchy;

// inspired by http://rosettacode.org/wiki/Number_names#C.2B.2B
const char *smallNumbers[] = {"oh",      "one",       "two",      "three",
                              "four",    "five",      "six",      "seven",
                              "eight",   "nine",      "ten",      "eleven",
                              "twelve",  "thirteen",  "fourteen", "fifteen",
                              "sixteen", "seventeen", "eighteen", "nineteen"};
const char *decades[] = {nullptr, nullptr, "twenty", "thirty", "forty", "fifty"};

void TimeScreen::show() {
  tmElements_t currentTime;
  Watchy::RTC.read(currentTime);
  DEBUG("TimeScreen::show currentTime %4d-%2d-%2d %02d:%02d:%02d %s\n",
                currentTime.Year+1970, currentTime.Month, currentTime.Day,
                currentTime.Hour, currentTime.Minute, currentTime.Second,
                dayShortStr(currentTime.Wday));
  time_t tt = makeTime(currentTime);
  DEBUG("TimeScreen::show tt %ld\n", tt);
  setenv("TZ", SyncTimeScreen::tz, 1);
  tzset();
  tm t;
  localtime_r(&tt, &t);

  // hour, just one line
  display.setFont(&OptimaLTStd_Bold22pt7b);
  display.setCursor(0, 0);
  display.printf("\n%s\n", smallNumbers[(t.tm_hour + 11) % 12 + 1]);  // 24->12

  // minutes, can be up to two lines
  display.setFont(&OptimaLTStd22pt7b);
  if (t.tm_min == 0) {
    // 0: exactly on the hour
    if (t.tm_hour == 0) {
      display.println("midnight");
    } else if (t.tm_hour == 12) {
      display.println("noon");
    } else {
      display.println("o'clock");
    }
  } else if (t.tm_min < 20) {
    display.println(smallNumbers[t.tm_min]);
  } else if (t.tm_min <= 59) {
    display.println(decades[t.tm_min / 10]);
    if (t.tm_min % 10 > 0) {
      display.println(smallNumbers[t.tm_min % 10]);
    }
  }

  // date
  display.setCursor(0, 195);
  display.setFont(&OptimaLTStd7pt7b);
  char buf[50];
  if (strftime(buf, sizeof(buf), "%A, %B %d %Y %Z", &t)) {
    display.print(buf);
  }
}