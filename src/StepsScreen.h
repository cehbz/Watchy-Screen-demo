#pragma once

#include "Screen.h"

class StepsScreen : public Screen {
 public:
  StepsScreen() : Screen("Steps"){};
  void show();
  void up();
  void down();
};

extern StepsScreen stepsScreen;