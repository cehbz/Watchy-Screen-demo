#pragma once

#include "Screen.h"

class UpdateFWScreen : public Screen {
 public:
  UpdateFWScreen(Screen *p = nullptr) : Screen(p) {}
  void show() override;
  void menu() override;
};