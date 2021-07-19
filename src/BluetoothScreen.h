#pragma once

#include "Screen.h"

class BluetoothScreen : public Screen {
 public:
  BluetoothScreen() : Screen("bluetooth"){};
  void show();
  void back();
  void up();
  void down();
};

extern BluetoothScreen bluetoothScreen;