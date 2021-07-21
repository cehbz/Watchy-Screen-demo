#include "StepsScreen.h"

#include "OptimaLTStd12pt7b.h"
#include "SettingsScreen.h"
#include "ShowStepsScreen.h"
#include "Watchy.h"
#include "WifiScreen.h"

void StepsScreen::show() {
  Watchy::display.setFont(&OptimaLTStd12pt7b);
  Watchy::display.setCursor(0, 0);
  Watchy::display.printf("\nsteps\n");
}