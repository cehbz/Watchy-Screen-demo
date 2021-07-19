#pragma once

#include "Screen.h"

class BluetoothScreen : public Screen {
 public:
  BluetoothScreen() : Screen("Bluetooth"){};
  void show();
  void up();
  void down();
};

extern BluetoothScreen bluetoothScreen;