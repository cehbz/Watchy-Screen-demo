#pragma once

#include "Screen.h"

class BatteryScreen : public Screen {
 public:
  BatteryScreen(Screen *p = nullptr) : Screen(p) {}
  void show() override;
};
