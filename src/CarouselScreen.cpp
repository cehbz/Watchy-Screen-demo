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

RTC_DATA_ATTR int8_t CarouselScreen::index;

CarouselScreen::CarouselScreen(CarouselItem *cis, const int8_t cs, Screen *p)
    : Screen(p), items(cis), size(cs) {
  for (int i = 0; i < size; i++) {
    if (items[i].splash != nullptr) {
      items[i].splash->parent = this;
    }
    if (items[i].child != nullptr) {
      items[i].child->parent = this;
    }
  }
}

void CarouselScreen::show() {
  DEBUG("CarouselScreen::show index %d\n", index);
  Watchy::showWatchFace(true, items[index].splash);
}

void CarouselScreen::menu() {
  DEBUG("CarouselScreen::menu index %d\n", index);
  if (items[index].child != nullptr) {
    Watchy::setScreen(items[index].child);
  }
}

void CarouselScreen::back() {
  DEBUG("CarouselScreen::back index %d\n", index);
  index = 0;
  show();
}

void CarouselScreen::up() {
  DEBUG("CarouselScreen::up index %d\n", index);
  index--;
  if (index < 0) {
    index = size - 1;
  }
  show();
}

void CarouselScreen::down() {
  DEBUG("CarouselScreen::down index %d\n", index);
  index++;
  if (index >= size) {
    index = 0;
  }
  show();
}
