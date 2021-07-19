#pragma once

#include "Screen.h"

class ShowStepsScreen : public Screen {
 public:
  ShowStepsScreen() : Screen("ShowSteps"){};
  void show();
  void back();
};

extern ShowStepsScreen showStepsScreen;