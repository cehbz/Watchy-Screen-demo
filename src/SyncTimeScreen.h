#pragma once

#include "Screen.h"

class SyncTimeScreen : public Screen {
 public:
  // these should probably live somewhere else (like in Watchy)
  // but can keep them here for now
  static const char *tz;
  static const char *ntpServer;

 public:
  SyncTimeScreen(Screen *p = nullptr) : Screen(p) {}
  void show() override;
  void back() override;
};