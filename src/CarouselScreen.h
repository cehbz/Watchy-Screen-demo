#pragma once

#include <array>

#include "Screen.h"

typedef struct {
  Screen *splash;
  Screen *child;  // can be nullptr
} CarouselItem;

class CarouselScreen : public Screen {
 private:
  static int8_t index;  // really this can only be a singleton for now
  CarouselItem *items;
  int8_t size;
  static bool active;

 public:
  CarouselScreen(Screen *p = nullptr) : Screen(p) {}
  void setItems(CarouselItem *cis, const int8_t cs) {
    items = cis;
    size = cs;
  }
  void show() override;
  void menu() override;
  void back() override;
  void up() override;
  void down() override;
};
