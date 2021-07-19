#pragma once

#include "Screen.h"

class ShowBatteryScreen : public Screen {
 public:
  ShowBatteryScreen() : Screen("showBattery"){};
  void show();
  void back();
};

extern ShowBatteryScreen showBatteryScreen;