#pragma once

#include "Screen.h"

class OrientationScreen : public Screen {
 public:
  OrientationScreen() : Screen("Orientation"){};
  void show();
  void back();
  void up();
  void down();
};

extern OrientationScreen orientationScreen;