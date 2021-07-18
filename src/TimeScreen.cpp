
#include "TimeScreen.h"

#include "OptimaLTStd22pt7b.h"
#include "OptimaLTStd7pt7b.h"
#include "OptimaLTStd_Bold22pt7b.h"

using namespace Watchy;

TimeScreen timeScreen;

const char *lows[13] = {"oh",   "one",    "two",   "three", "four",
                        "five", "six",    "seven", "eight", "nine",
                        "ten",  "eleven", "twelve"};
const char *teens[9] = {"eleven",    "twelve",   "thirteen",
                        "fourteen",  "fifteen",  "sixteen",
                        "seventeen", "eighteen", "nineteen"};
const char *tens[6] = {"oh", "ten", "twenty", "thirty", "forty", "fifty"};

void TimeScreen::show() {
  tmElements_t currentTime;
  Watchy::RTC.read(currentTime);
  Serial.printf("TimeScreen::show currentTime %02d:%02d %d/%d/%d (%d)\n",
                currentTime.Hour, currentTime.Minute, currentTime.Year,
                currentTime.Month, currentTime.Day, currentTime.Wday);

  // hour, just one line
  display.setFont(&OptimaLTStd_Bold22pt7b);
  display.setCursor(0, 0);
  display.printf("\n%s\n", lows[(currentTime.Hour + 11) % 12 + 1]);  // 24->12

  // minutes, can be up to two lines
  display.setFont(&OptimaLTStd22pt7b);
  if (currentTime.Minute == 0) {
    // 0: exactly on the hour
    if (currentTime.Hour == 0) {
      display.println("midnight");
    } else if (currentTime.Hour == 12) {
      display.println("noon");
    } else {
      display.println("o'clock");
    }
  } else if (11 <= currentTime.Minute && currentTime.Minute <= 19) {
    // 11-19
    display.println(teens[currentTime.Minute - 11]);
  } else if (currentTime.Minute <= 59) {
    // 1-10 or 20-59
    display.println(tens[currentTime.Minute / 10]);
    if (currentTime.Minute % 10 > 0) {
      display.println(lows[currentTime.Minute % 10]);
    }
  }

  // date
  display.setCursor(0, 195);
  display.setFont(&OptimaLTStd7pt7b);
  // dayStr and monthStr use the same static buffer
  display.print(dayStr(currentTime.Wday));
  display.printf(", %s %d %d\n", monthStr(currentTime.Month), currentTime.Day,
                 currentTime.Year + YEAR_OFFSET);
}
void TimeScreen::up() { Watchy::setScreen(&weather); };
void TimeScreen::down() { Watchy::setScreen(&weather); };
