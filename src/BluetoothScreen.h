#pragma once

#include "Screen.h"

class BluetoothScreen : public Screen {
 public:
  BluetoothScreen(Screen *p = nullptr) : Screen(p) {}
  void show() override;
};