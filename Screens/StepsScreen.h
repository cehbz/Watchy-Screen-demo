#pragma once

#include "Screen.h"

class StepsScreen : public Screen {
 public:
  StepsScreen(Screen *p = nullptr) : Screen(p) {}
  void show() override;
};
