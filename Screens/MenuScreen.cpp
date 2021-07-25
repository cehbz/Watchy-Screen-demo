#include "MenuScreen.h"

#include "SetTimeScreen.h"
#include "SettingsScreen.h"
#include "SetupWifiScreen.h"
#include "UpdateFWScreen.h"
#include "Watchy.h"

using namespace Watchy;

const int MENU_HEIGHT = 30;

RTC_DATA_ATTR int8_t MenuScreen::index;

MenuScreen::MenuScreen(MenuItem *mis, const int8_t ms, Screen *p)
    : Screen(p), items(mis), size(ms) {
  for (int i = 0; i < size; i++) {
    if (items[i].screen != nullptr) {
      items[i].screen->parent = this;
    }
  }
}

void MenuScreen::show() {
  DEBUG("MenuScreen::show index %d\n", index);
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

void MenuScreen::menu() { Watchy::setScreen(items[index].screen); }

void MenuScreen::back() { setScreen(parent); }

void MenuScreen::up() {
  index--;
  if (index < 0) {
    index = size - 1;
  }
  showWatchFace(true);
}

void MenuScreen::down() {
  index++;
  if (index >= size) {
    index = 0;
  }
  showWatchFace(true);
}
