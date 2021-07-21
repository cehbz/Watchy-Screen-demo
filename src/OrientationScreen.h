#pragma once

#include "Screen.h"

class OrientationScreen : public Screen {
 public:
  OrientationScreen(Screen *p = nullptr) : Screen(p) {}
  void show() override;
};
