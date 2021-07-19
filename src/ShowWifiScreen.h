#pragma once

#include "Screen.h"

class ShowWifiScreen : public Screen {
 public:
  ShowWifiScreen() : Screen("ShowWifi"){};
  void show();
  void back();
};

extern ShowWifiScreen showWifiScreen;