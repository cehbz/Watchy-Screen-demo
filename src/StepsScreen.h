#pragma once

#include "Screen.h"

class StepsScreen : public Screen {
 public:
  StepsScreen() : Screen("Steps"){};
  void show();
  void back();
  void menu();
  void up();
  void down();
};

extern StepsScreen stepsScreen;