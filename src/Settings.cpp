#include "Settings.h"

#include "Watchy.h"

void Settings::show() {}
void Settings::up() { Watchy::setScreen(Watchy::defaultScreen); }
void Settings::down() { Watchy::setScreen(Watchy::defaultScreen); }
Settings settings;