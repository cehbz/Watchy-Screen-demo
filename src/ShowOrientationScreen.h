#pragma once

#include "Screen.h"

class ShowOrientationScreen : public Screen {
 public:
  ShowOrientationScreen() : Screen("ShowOrientation"){};
  void show();
  void back();
};

extern ShowOrientationScreen showOrientationScreen;