#pragma once

#include "Screen.h"

class MenuScreen : public Screen {
 private:
  static int menuIndex;
  void doMenu(int index);

 public:
  MenuScreen() : Screen("MenuScreen"){};
  virtual void show();
  virtual void menu();
  virtual void back();
  virtual void up();
  virtual void down();
};

extern MenuScreen menuScreen;