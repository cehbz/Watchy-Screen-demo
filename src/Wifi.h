#pragma once

#include "Screen.h"
#include "Weather.h"

class Wifi : public Screen {
 public:
  Wifi() : Screen("Wifi"){};
  void show();
  void up();
  void down();
};

extern Wifi wifi;