#pragma once

#include "Screen.h"

class ShowOrientationScreen : public Screen {
 public:
  ShowOrientationScreen(Screen *p = nullptr) : Screen(p) {}
  void show() override;
};