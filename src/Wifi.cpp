#include "Wifi.h"

#include "Watchy.h"

void Wifi::show() {}
void Wifi::up() { Watchy::setScreen(Watchy::defaultScreen); }
void Wifi::down() { Watchy::setScreen(Watchy::defaultScreen); }
Wifi wifi;