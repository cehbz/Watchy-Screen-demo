#pragma once

#include "Screen.h"

class SetupWifiScreen : public Screen {
 public:
  SetupWifiScreen(Screen *p = nullptr) : Screen(p) {}
  void show() override;
};
