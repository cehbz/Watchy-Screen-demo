#include "StepsScreen.h"

#include "OptimaLTStd12pt7b.h"
#include "Watchy.h"

void StepsScreen::show() {
  Watchy::display.setFont(&OptimaLTStd12pt7b);
  Watchy::display.setCursor(0, 0);
  Watchy::display.printf("\nSteps\n");
}
void StepsScreen::up() { Watchy::setScreen(Watchy::defaultScreen); }
void StepsScreen::down() { Watchy::setScreen(Watchy::defaultScreen); }

StepsScreen stepsScreen;