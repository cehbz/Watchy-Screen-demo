#include "BluetoothScreen.h"

#include "Adafruit_GFX.h"
#include "OptimaLTStd22pt7b.h"
#include "Watchy.h"
#include "icons.h"

void BluetoothScreen::show() {
  constexpr char *label = "bluetooth";
  const uint16_t fgColor = (bgColor == GxEPD_WHITE ? GxEPD_BLACK : GxEPD_WHITE);
  Watchy::display.setFont(&OptimaLTStd22pt7b);
  int16_t x1, y1;
  uint16_t w, h;
  Watchy::display.drawBitmap((200 - 96) / 2, (200 - 96) / 2 / 2,
                             bitmap_bluetooth, 96, 96, fgColor);
  Watchy::display.getTextBounds(label, 0, 0, &x1, &y1, &w, &h);
  Watchy::display.setCursor((200 - w) / 2, 170);
  Watchy::display.print(label);
}