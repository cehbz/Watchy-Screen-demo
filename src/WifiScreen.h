#pragma once

#include "Screen.h"

class WifiScreen : public Screen {
 public:
  WifiScreen(Screen *p = nullptr) : Screen(p) {}
  void show() override;
};
