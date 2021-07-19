#pragma once

#include "Screen.h"

class SetTimeScreen : public Screen {
 public:
  int8_t minute;
  int8_t hour;
  int8_t day;
  int8_t month;
  int8_t year;

 public:
  SetTimeScreen() : Screen("SetTimeScreen"){};
  void show();
};

extern SetTimeScreen setTimeScreen;