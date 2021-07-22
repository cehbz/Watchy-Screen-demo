#pragma once

#include "Screen.h"

typedef struct {
  const char *name;
  Screen *screen;
} MenuItem;

class MenuScreen : public Screen {
 private:
  static int8_t index;
  MenuItem *items;  // array of MenuItems
  uint8_t size;
  static bool active;

 public:
  MenuScreen(MenuItem *mis, const int8_t ms, Screen *p = nullptr);
  void show() override;
  void menu() override;
  void back() override;
  void up() override;
  void down() override;
};