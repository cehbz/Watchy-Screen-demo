#include "TimeScreen.h"
#include "Watchy.h"

void setup() {
  Serial.begin(921600);
  DEBUG("  %ld: setup %d\n", millis(), esp_sleep_get_wakeup_cause());

  Watchy::defaultScreen = &timeScreen;
  Watchy::init();
}

void loop() {}  // this should never run, Watchy deep sleeps after init();