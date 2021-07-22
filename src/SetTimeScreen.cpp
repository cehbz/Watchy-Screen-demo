#include "SetTimeScreen.h"

#include "MenuScreen.h"
#include "Watchy.h"

using namespace Watchy;

const int SET_HOUR = 0;
const int SET_MINUTE = 1;
const int SET_YEAR = 2;
const int SET_MONTH = 3;
const int SET_DAY = 4;

bool blink;
bool revert;
bool commit;

RTC_DATA_ATTR uint8_t SetTimeScreen::setIndex;

typedef struct {
  int8_t SetTimeScreen::*val;
  int8_t min;
  int8_t max;
} Field;

void decrMin(int8_t &val, int8_t &min, int8_t &max) {
  if (val-- <= min) {
    val = max;
  }
}

void incrMax(int8_t &val, int8_t &min, int8_t &max) {
  if (val++ >= max) {
    val = min;
  }
}

Field fields[] = {{&SetTimeScreen::hour, 0, 23},
                  {&SetTimeScreen::minute, 0, 59},
                  {&SetTimeScreen::year, 20, 99},
                  {&SetTimeScreen::month, 1, 12},
                  {&SetTimeScreen::day, 1, 31}};
const uint8_t numFields = sizeof(fields) / sizeof(fields[0]);

void SetTimeScreen::show() {
  DEBUG("SetTimeScreen::show index %d\n", setIndex);
  tmElements_t currentTime;
  RTC.read(currentTime);

  minute = currentTime.Minute;
  hour = currentTime.Hour;
  day = currentTime.Day;
  month = currentTime.Month;
  year = currentTime.Year + YEAR_OFFSET - 2000;

  blink = 0;
  revert = false;
  commit = false;

  pinMode(DOWN_BTN_PIN, INPUT);
  pinMode(UP_BTN_PIN, INPUT);
  pinMode(MENU_BTN_PIN, INPUT);
  pinMode(BACK_BTN_PIN, INPUT);

  while (!revert && !commit) {
    while (!pollButtonsAndDispatch()) {
      blink = 1 - blink;
      const uint16_t fgColor =
          (screen->bgColor == GxEPD_WHITE ? GxEPD_BLACK : GxEPD_WHITE);

      display.fillScreen(screen->bgColor);
      display.setFont(&DSEG7_Classic_Bold_53);
      display.setTextColor(fgColor);

      display.setCursor(5, 80);
      if (setIndex == SET_HOUR) {  // blink hour digits
        display.setTextColor(blink ? fgColor : screen->bgColor);
      }
      display.printf("%02d", hour);

      display.setTextColor(fgColor);
      display.print(":");

      display.setCursor(108, 80);
      if (setIndex == SET_MINUTE) {  // blink minute digits
        display.setTextColor(blink ? fgColor : screen->bgColor);
      }
      display.printf("%02d", minute);

      display.setTextColor(fgColor);

      display.setFont(&FreeMonoBold9pt7b);
      display.setCursor(45, 150);
      if (setIndex == SET_YEAR) {  // blink minute digits
        display.setTextColor(blink ? fgColor : screen->bgColor);
      }
      display.print(1970 + year);

      display.setTextColor(fgColor);
      display.print("/");

      if (setIndex == SET_MONTH) {  // blink minute digits
        display.setTextColor(blink ? fgColor : screen->bgColor);
      }
      display.printf("%02d", month);

      display.setTextColor(fgColor);
      display.print("/");

      if (setIndex == SET_DAY) {  // blink minute digits
        display.setTextColor(blink ? fgColor : screen->bgColor);
      }
      display.printf("%02d", day);
      display.display(true);  // partial refresh
    }
    yield();
  }

  if (commit) {
    const time_t FUDGE(
        10);  // fudge factor to allow for upload time, etc. (seconds, YMMV)
    tmElements_t tm;
    tm.Month = month;
    tm.Day = day;
    tm.Year = year + 2000 -
              YEAR_OFFSET;  // offset from 1970, since year is stored in uint8_t
    tm.Hour = hour;
    tm.Minute = minute;
    tm.Second = 0;

    time_t t = makeTime(tm) + FUDGE;
    RTC.set(t);
  }
  setIndex = 0; // make sure we start at the beginning if we come back
  DEBUG("SetTimeScreen done. Setting screen to %08lx\n",(unsigned long)parent);
  Watchy::setScreen(parent ? parent : Watchy::defaultScreen);
}

void SetTimeScreen::up() {
  DEBUG("SetTimeScreen::up index %d\n", setIndex);
  decrMin(this->*(fields[setIndex].val), fields[setIndex].min,
          fields[setIndex].max);
}

void SetTimeScreen::down() {
  DEBUG("SetTimeScreen::down index %d\n", setIndex);
  incrMax(this->*(fields[setIndex].val), fields[setIndex].min,
          fields[setIndex].max);
}

void SetTimeScreen::back() {
  DEBUG("SetTimeScreen::back index %d\n", setIndex);
  if (setIndex == 0) {
    revert = true;
  } else {
    setIndex--;
  }
}

void SetTimeScreen::menu() {
  DEBUG("SetTimeScreen::menu index %d\n", setIndex);
  if (setIndex == numFields-1) {
    commit = true;
  } else {
    setIndex++;
  }
}