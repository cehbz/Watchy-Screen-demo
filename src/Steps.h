#pragma once

#include "Screen.h"
#include "Weather.h"

class Steps : public Screen {
 public:
  Steps() : Screen("Steps"){};
  void show();
  void up();
  void down();
};

extern Steps steps;