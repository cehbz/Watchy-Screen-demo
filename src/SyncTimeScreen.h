#pragma once

#include "Screen.h"

class SyncTimeScreen : public Screen {
 public:
  SyncTimeScreen(Screen *p = nullptr) : Screen(p) {}
  void show() override;
};