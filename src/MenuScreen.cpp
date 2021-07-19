#include "MenuScreen.h"

#include <array>

#include "SetTimeScreen.h"
#include "SettingsScreen.h"
#include "SetupWifiScreen.h"
#include "UpdateFWScreen.h"
#include "Watchy.h"

using namespace Watchy;

// consder using std::array
const std::array<const char*, 3> menuItems = {"Set Time", "Setup WiFi",
                                              "Update Firmware"};

const int MENU_HEIGHT = 30;

RTC_DATA_ATTR int MenuScreen::menuIndex;

void MenuScreen::show() {
  DEBUG("MenuScreen::show index %d\n", menuIndex);
  const uint16_t fgColor =
      (screen->bgColor == GxEPD_WHITE ? GxEPD_BLACK : GxEPD_WHITE);
  display.setFont(&FreeMonoBold9pt7b);

  uint8_t i = 0;
  for (const auto& mi : menuItems) {
    int16_t yPos = 30 + (MENU_HEIGHT * i);
    display.setCursor(0, yPos);
    if (i == menuIndex) {
      int16_t x1, y1;
      uint16_t w, h;

      display.getTextBounds(mi, 0, yPos, &x1, &y1, &w, &h);
      display.fillRect(x1 - 1, y1 - 10, 200, h + 15, fgColor);
      display.setTextColor(bgColor);
      display.println(mi);
    } else {
      display.setTextColor(fgColor);
      display.println(mi);
    }
    i++;
  }
}

void MenuScreen::menu() { doMenu(menuIndex); }

void MenuScreen::back() { setScreen(&settingsScreen); }

void MenuScreen::up() {
  menuIndex--;
  if (menuIndex < 0) {
    menuIndex = menuItems.size() - 1;
  }
  showWatchFace(true);
}

void MenuScreen::down() {
  menuIndex++;
  if (menuIndex >= menuItems.size()) {
    menuIndex = 0;
  }
  showWatchFace(true);
}

MenuScreen menuScreen;

void MenuScreen::doMenu(int index) {
  switch (index) {
    case 0:
      setScreen(&setTimeScreen);
      break;
    case 1:
      setScreen(&setupWifiScreen);
      break;
    case 2:
      setScreen(&updateFWScreen);
      break;
    default:
      break;
  }
}