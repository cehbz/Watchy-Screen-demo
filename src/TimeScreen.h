#pragma once

#include "Screen.h"

class TimeScreen : public Screen {
 public:
  TimeScreen() : Screen("Time"){};
  void show();
  void down();
};

extern TimeScreen timeScreen;