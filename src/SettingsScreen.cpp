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
void SettingsScreen::back() { Watchy::setScreen(Watchy::defaultScreen); }
void SettingsScreen::menu() { Watchy::setScreen(&menuScreen); }
void SettingsScreen::up() { Watchy::setScreen(&orientationScreen); }
void SettingsScreen::down() { Watchy::setScreen(&stepsScreen); }

SettingsScreen settingsScreen;