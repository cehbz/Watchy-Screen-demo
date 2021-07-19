#pragma once

#include "Screen.h"

class BatteryScreen : public Screen {
 public:
  BatteryScreen() : Screen("Battery"){};
  void show();
  void back();
  void up();
  void down();
};

extern BatteryScreen batteryScreen;