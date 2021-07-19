#pragma once

#include "Screen.h"

class WifiScreen : public Screen {
 public:
  WifiScreen() : Screen("Wifi"){};
  void show();
  void back();
  void menu();
  void up();
};

extern WifiScreen wifiScreen;