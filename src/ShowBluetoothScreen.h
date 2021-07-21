#pragma once

#include "Screen.h"

class ShowBluetoothScreen : public Screen {
 public:
  ShowBluetoothScreen(Screen *p = nullptr) : Screen(p) {}
  void show() override;
};