#include "SettingsScreen.h"

#include "OptimaLTStd12pt7b.h"
#include "Watchy.h"
#include "MenuScreen.h"
#include "OrientationScreen.h"
#include "StepsScreen.h"

void SettingsScreen::show() {
  Watchy::display.setFont(&OptimaLTStd12pt7b);
  Watchy::display.setCursor(0, 0);
  Watchy::display.printf("\nsettings\n");
}