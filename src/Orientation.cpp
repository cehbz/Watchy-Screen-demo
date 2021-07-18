#include "Orientation.h"

#include "Watchy.h"

void Orientation::show() {}
void Orientation::up() { Watchy::setScreen(Watchy::defaultScreen); }
void Orientation::down() { Watchy::setScreen(Watchy::defaultScreen); }
Orientation orientation;