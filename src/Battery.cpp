#include "Battery.h"

#include "Watchy.h"

void Battery::show() {}
void Battery::up() { Watchy::setScreen(Watchy::defaultScreen); }
void Battery::down() { Watchy::setScreen(Watchy::defaultScreen); }
Battery battery;