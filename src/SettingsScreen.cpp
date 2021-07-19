#include "SettingsScreen.h"

#include "OptimaLTStd12pt7b.h"
#include "Watchy.h"

void SettingsScreen::show() {
  Watchy::display.setFont(&OptimaLTStd12pt7b);
  Watchy::display.setCursor(0, 0);
  Watchy::display.printf("\nSettings\n");
}
void SettingsScreen::up() { Watchy::setScreen(Watchy::defaultScreen); }
void SettingsScreen::down() { Watchy::setScreen(Watchy::defaultScreen); }

SettingsScreen settingsScreen;