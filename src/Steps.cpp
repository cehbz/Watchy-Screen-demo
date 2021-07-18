#include "Steps.h"

#include "Watchy.h"

void Steps::show() {}
void Steps::up() { Watchy::setScreen(Watchy::defaultScreen); }
void Steps::down() { Watchy::setScreen(Watchy::defaultScreen); }
Steps steps;