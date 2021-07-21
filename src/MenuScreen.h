#pragma once

#include "Screen.h"

typedef struct {
  const char *name;
  Screen *screen;
} MenuItem;

class MenuScreen : public Screen {
 private:
  static uint8_t index;
  MenuItem *items;  // array of MenuItems
  uint8_t size;
  static bool active;

 public:
  MenuScreen(Screen *p = nullptr) : Screen(p) {}
  void setItems(MenuItem *mis, const uint8_t ms) {
    items = mis;
    size = ms;
  }
  void show() override;
  void menu() override;
  void back() override;
  void up() override;
  void down() override;
};