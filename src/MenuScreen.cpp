#include "MenuScreen.h"

#include "SetTimeScreen.h"
#include "SettingsScreen.h"
#include "SetupWifiScreen.h"
#include "UpdateFWScreen.h"
#include "Watchy.h"

using namespace Watchy;

const int MENU_HEIGHT = 30;

RTC_DATA_ATTR uint8_t MenuScreen::index;
RTC_DATA_ATTR bool MenuScreen::active;

void MenuScreen::show() {
  DEBUG("MenuScreen::show index %d\n", index);
  if (active) {
    Watchy::showWatchFace(true, items[index].screen);
    return;
  }
  const uint16_t fgColor =
      (screen->bgColor == GxEPD_WHITE ? GxEPD_BLACK : GxEPD_WHITE);
  display.setFont(&FreeMonoBold9pt7b);

  for (uint8_t i = 0; i < size; i++) {
    int16_t yPos = 30 + (MENU_HEIGHT * i);
    display.setCursor(0, yPos);
    if (i == index) {
      int16_t x1, y1;
      uint16_t w, h;

      display.getTextBounds(items[i].name, 0, yPos, &x1, &y1, &w, &h);
      display.fillRect(x1 - 1, y1 - 10, 200, h + 15, fgColor);
      display.setTextColor(bgColor);
      display.println(items[i].name);
    } else {
      display.setTextColor(fgColor);
      display.println(items[i].name);
    }
  }
}

void MenuScreen::menu() {
  if (active) {
    items[index].screen->menu();
  } else {
    active = true;
    show();
  }
}
void MenuScreen::back() {
  if (active) {
    active = false;
    show();
  } // else { return to parent, handled by parent }
}

void MenuScreen::up() {
  if (active) {
    items[index].screen->up();
    return;
  }
  index--;
  if (index < 0) {
    index = size - 1;
  }
  showWatchFace(true);
}

void MenuScreen::down() {
  if (active) {
    items[index].screen->down();
    return;
  }

  index++;
  if (index >= size) {
    index = 0;
  }
  showWatchFace(true);
}
