#pragma once

#include "Screen.h"

class BatteryScreen : public Screen {
 public:
  BatteryScreen() : Screen("battery"){};
  void show();
  void back();
  void menu();
  void up();
  void down();
};

extern BatteryScreen batteryScreen;