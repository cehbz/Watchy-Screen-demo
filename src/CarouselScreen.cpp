#include "CarouselScreen.h"

#include "BatteryScreen.h"
#include "BluetoothScreen.h"
#include "OrientationScreen.h"
#include "SettingsScreen.h"
#include "StepsScreen.h"
#include "TimeScreen.h"
#include "Watchy.h"
#include "WeatherScreen.h"
#include "WifiScreen.h"

using namespace Watchy;

RTC_DATA_ATTR uint8_t CarouselScreen::index;
RTC_DATA_ATTR bool CarouselScreen::active;

void CarouselScreen::show() {
  Watchy::showWatchFace(true, items[index].splash);
}

void CarouselScreen::menu() {
  if (items[index].child != nullptr) {
    Watchy::setScreen(items[index].child);
  }
}

void CarouselScreen::back() {
  index = 0;
  show();
}

void CarouselScreen::up() {
  index--;
  if (index < 0) {
    index = size - 1;
  }
  show();
}

void CarouselScreen::down() {
  index++;
  if (index >= size) {
    index = 0;
  }
  show();
}
