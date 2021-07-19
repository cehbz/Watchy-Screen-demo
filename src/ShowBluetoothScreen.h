#pragma once

#include "Screen.h"

class ShowBluetoothScreen : public Screen {
 public:
  ShowBluetoothScreen() : Screen("showBluetooth"){};
  void show();
  void back();
};

extern ShowBluetoothScreen showBluetoothScreen;