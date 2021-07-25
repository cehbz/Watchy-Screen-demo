#pragma once

#include "Screen.h"

class WeatherScreen : public Screen {
 public:
  WeatherScreen(Screen *p = nullptr) : Screen(p) {}
  void show() override;
};
