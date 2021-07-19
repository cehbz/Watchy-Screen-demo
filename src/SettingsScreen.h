#pragma once

#include "Screen.h"

class SettingsScreen : public Screen {
 public:
  SettingsScreen() : Screen("Settings"){};
  void show();
  void back();
  void up();
  void down();
};

extern SettingsScreen settingsScreen;