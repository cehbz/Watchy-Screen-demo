#pragma once

#include "Screen.h"
#include "Weather.h"

class Orientation : public Screen {
 public:
  Orientation() : Screen("Orientation"){};
  void show();
  void up();
  void down();
};

extern Orientation orientation;