#pragma once

#include "Screen.h"

class WeatherScreen : public Screen {
 public:
  WeatherScreen() : Screen("Weather"){};
  void show();
  void back();
  void up();
  void down();
};

extern WeatherScreen weatherScreen;