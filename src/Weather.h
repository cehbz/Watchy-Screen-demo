#pragma once

#include "Screen.h"
#include "TimeScreen.h"

class Weather : public Screen {
 public:
  Weather() : Screen("Weather"){};
  void show();
  void up();
  void down();
};

extern Weather weather;