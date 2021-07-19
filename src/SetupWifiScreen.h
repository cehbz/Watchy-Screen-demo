#pragma once

#include "Screen.h"

class SetupWifiScreen : public Screen {
 public:
  SetupWifiScreen() : Screen("SetupWifiScreen"){};
  void show();
};

extern SetupWifiScreen setupWifiScreen;