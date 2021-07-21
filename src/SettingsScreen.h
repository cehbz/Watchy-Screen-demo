#pragma once

#include "Screen.h"

class SettingsScreen : public Screen {
 public:
  SettingsScreen(Screen *p = nullptr) : Screen(p) {}
  void show() override;
};
