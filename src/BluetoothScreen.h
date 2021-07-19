#pragma once

#include "Screen.h"

class BluetoothScreen : public Screen {
 public:
  BluetoothScreen() : Screen("bluetooth"){};
  void show();
  void back();
  void menu();
  void up();
  void down();
};

extern BluetoothScreen bluetoothScreen;