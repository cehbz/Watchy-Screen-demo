#pragma once

#include "Screen.h"

class ShowStepsScreen : public Screen {
 public:
  ShowStepsScreen(Screen *p = nullptr) : Screen(p) {}
  void show() override;
};
