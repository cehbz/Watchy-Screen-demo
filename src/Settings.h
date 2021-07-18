#pragma once

#include "Screen.h"
#include "Weather.h"

class Settings : public Screen {
 public:
  Settings() : Screen("Settings"){};
  void show();
  void up();
  void down();
};

extern Settings bluetooth;