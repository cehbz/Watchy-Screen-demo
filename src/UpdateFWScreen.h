#pragma once

#include "Screen.h"

class UpdateFWScreen : public Screen {
 public:
  UpdateFWScreen() : Screen("UpdateFWScreen"){};
  void show();
  void back();
  void menu();
};

extern UpdateFWScreen updateFWScreen;
