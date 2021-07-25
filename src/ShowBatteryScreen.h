#pragma once

#include "Screen.h"

class ShowBatteryScreen : public Screen {
 public:
  ShowBatteryScreen(Screen *p = nullptr) : Screen(p) {}
  void show() override;
};
