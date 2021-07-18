#include "Bluetooth.h"

#include "Watchy.h"

void Bluetooth::show() {}
void Bluetooth::up() { Watchy::setScreen(Watchy::defaultScreen); }
void Bluetooth::down() { Watchy::setScreen(Watchy::defaultScreen); }
Bluetooth bluetooth;