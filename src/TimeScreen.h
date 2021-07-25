#pragma once

#include "Screen.h"

class TimeScreen : public Screen {
 public:
  TimeScreen(Screen *p = nullptr) : Screen(p) {}
  void show();
};
