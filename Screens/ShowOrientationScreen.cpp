#include "ShowOrientationScreen.h"

#include "OptimaLTStd22pt7b.h"
#include "OrientationScreen.h"
#include "SettingsScreen.h"
#include "Watchy.h"

void ShowOrientationScreen::show() {
  Watchy::display.setFont(&OptimaLTStd22pt7b);
  Watchy::display.setCursor(0, 0);
  Watchy::display.printf("\ndirection\n");
  uint8_t direction = Watchy::sensor.getDirection();
  switch (direction) {
    case DIRECTION_DISP_DOWN:
      Watchy::display.print("down");
      break;
    case DIRECTION_DISP_UP:
      Watchy::display.print("up");
      break;
    case DIRECTION_BOTTOM_EDGE:
      Watchy::display.print("bottom");
      break;
    case DIRECTION_TOP_EDGE:
      Watchy::display.print("top");
      break;
    case DIRECTION_RIGHT_EDGE:
      Watchy::display.print("right");
      break;
    case DIRECTION_LEFT_EDGE:
      Watchy::display.print("left");
      break;
    default:
      Watchy::display.printf("%d ???", direction);
      break;
  }
}
