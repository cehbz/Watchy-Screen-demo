#pragma once

#include "Screen.h"
#include "Weather.h"

class Battery : public Screen {
 public:
  Battery() : Screen("Battery"){};
  void show();
  void up();
  void down();
};

extern Battery battery;