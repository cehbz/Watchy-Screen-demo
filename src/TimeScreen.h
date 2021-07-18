#pragma once

#include "Screen.h"
#include "Weather.h"

class TimeScreen : public Screen {
 public:
  TimeScreen() : Screen("Time"){};
  void show();
  void up();
  void down();
};

extern TimeScreen timeScreen;