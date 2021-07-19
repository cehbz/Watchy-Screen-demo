#include "SetTimeScreen.h"

#include "MenuScreen.h"
#include "Watchy.h"

using namespace Watchy;

const int SET_HOUR = 0;
const int SET_MINUTE = 1;
const int SET_YEAR = 2;
const int SET_MONTH = 3;
const int SET_DAY = 4;

SetTimeScreen setTimeScreen;

bool blink;
bool revert;
bool commit;

void decrMin(int8_t& v, const int8_t& lo, const int8_t& hi) {
  if (v-- <= lo) {
    v = hi;
  }
}

void incrMax(int8_t& v, const int8_t& lo, const int8_t& hi) {
  if (v++ >= hi) {
    v = lo;
  }
}

void _show(int8_t setIndex);

class SetHour : public Screen {
 public:
  SetHour() : Screen("SetHour") {}
  void show() { _show(SET_HOUR); }
  void up() { decrMin(setTimeScreen.hour, 0, 23); }
  void down() { incrMax(setTimeScreen.hour, 0, 23); }
  void back() { revert = true; }
  void menu();
} setHour;

class SetMinute : public Screen {
 public:
  SetMinute() : Screen("SetMinute") {}
  void show() { _show(SET_MINUTE); }
  void up() { decrMin(setTimeScreen.minute, 0, 59); }
  void down() { incrMax(setTimeScreen.minute, 0, 59); }
  void back() { screen = &setHour; }
  void menu();
} setMinute;

void SetHour::menu() { screen = &setMinute; }

class SetYear : public Screen {
 public:
  SetYear() : Screen("SetYear") {}
  void show() { _show(SET_YEAR); }
  void up() { decrMin(setTimeScreen.year, 20, 99); }
  void down() { incrMax(setTimeScreen.year, 20, 99); }
  void back() { screen = &setMinute; }
  void menu();
} setYear;

void SetMinute::menu() { screen = &setYear; }

class SetMonth : public Screen {
 public:
  SetMonth() : Screen("SetMonth") {}
  void show() { _show(SET_MONTH); }
  void up() { decrMin(setTimeScreen.month, 1, 12); }
  void down() { incrMax(setTimeScreen.month, 1, 12); }
  void back() { screen = &setYear; }
  void menu();
} setMonth;

void SetYear::menu() { screen = &setMonth; }

class SetDay : public Screen {
 public:
  SetDay() : Screen("SetDay") {}
  void show() { _show(SET_DAY); }
  void up() { decrMin(setTimeScreen.day, 1, 31); }
  void down() { incrMax(setTimeScreen.day, 1, 31); }
  void back() { screen = &setMonth; }
  void menu() { commit = true; }
} setDay;

void SetMonth::menu() { screen = &setDay; }

void _show(int8_t setIndex) {
  DEBUG("SetTimeScreen::_show(%d)\n", setIndex);
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
    display.printf("%02d", setTimeScreen.hour);

    display.setTextColor(fgColor);
    display.print(":");

    display.setCursor(108, 80);
    if (setIndex == SET_MINUTE) {  // blink minute digits
      display.setTextColor(blink ? fgColor : screen->bgColor);
    }
    display.printf("%02d", setTimeScreen.minute);

    display.setTextColor(fgColor);

    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(45, 150);
    if (setIndex == SET_YEAR) {  // blink minute digits
      display.setTextColor(blink ? fgColor : screen->bgColor);
    }
    display.print(1970 + setTimeScreen.year);

    display.setTextColor(fgColor);
    display.print("/");

    if (setIndex == SET_MONTH) {  // blink minute digits
      display.setTextColor(blink ? fgColor : screen->bgColor);
    }
    display.printf("%02d", setTimeScreen.month);

    display.setTextColor(fgColor);
    display.print("/");

    if (setIndex == SET_DAY) {  // blink minute digits
      display.setTextColor(blink ? fgColor : screen->bgColor);
    }
    display.printf("%02d", setTimeScreen.day);
    display.display(true);  // partial refresh}
  }
}

void SetTimeScreen::show() {
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

  screen = &setHour;
  while (!revert && !commit) {
    showWatchFace(true);
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
  setScreen(&menuScreen);
}
