#include "OrientationScreen.h"

#include "OptimaLTStd12pt7b.h"
#include "Watchy.h"

void OrientationScreen::show() {
  Watchy::display.setFont(&OptimaLTStd12pt7b);
  Watchy::display.setCursor(0, 0);
  Watchy::display.printf("\nOrientation\n");
}
void OrientationScreen::up() { Watchy::setScreen(Watchy::defaultScreen); }
void OrientationScreen::down() { Watchy::setScreen(Watchy::defaultScreen); }

OrientationScreen orientationScreen;