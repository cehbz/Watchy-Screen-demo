#pragma once

#include "Screen.h"

class ShowWifiScreen : public Screen {
 public:
  ShowWifiScreen(Screen *p = nullptr) : Screen(p) {}
  void show() override;
};
