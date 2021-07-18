#pragma once

#include "Screen.h"
#include "Weather.h"

class Bluetooth : public Screen {
 public:
  Bluetooth() : Screen("Bluetooth"){};
  void show();
  void up();
  void down();
};

extern Bluetooth bluetooth;