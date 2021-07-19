#include "UpdateFWScreen.h"

#include "MenuScreen.h"
#include "Screen.h"
#include "Watchy.h"

using namespace Watchy;

UpdateFWScreen updateFWScreen;

class : public Screen {
  void show() {
    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(0, 30);
    display.println("BLE Connected!");
    display.println();
    display.println("Waiting for");
    display.println("upload...");
  }
} updateFWConnectedScreen;

class : public Screen {
  void show() {
    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(0, 30);
    display.println("Download");
    display.println("completed!");
    display.println();
    display.println("Rebooting...");
  }
} updateFWDownloadCompleteScreen;

class : public Screen {
  void show() {
    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(0, 30);
    display.println("BLE Disconnected!");
    display.println();
    display.println("exiting...");
  }
} updateFWDisconnectedScreen;

void btPoll() {
  BLE BT;

  // this local class variable only works because we
  // never deep sleep while doing BLE OTA
  class updateFWDownloadingScreen : public Screen {
   private:
    BLE &BT;

   public:
    updateFWDownloadingScreen(BLE &bt)
        : Screen("updateFWDownloadingScreen"), BT(bt) {}
    void show() {
      display.setFont(&FreeMonoBold9pt7b);
      display.setCursor(0, 30);
      display.println("Downloading");
      display.println("firmware:");
      display.println();
      display.printf("%d bytes", BT.howManyBytes());
    }
  } updateFWDownloadingScreen(BT);

  BT.begin("Watchy BLE OTA");

  int prevStatus = -1;
  int currentStatus;

  // only exits on download complete, or disconnect
  while (1) {
    currentStatus = BT.updateStatus();
    if (prevStatus != currentStatus) {
      switch (currentStatus) {
        case 0:
          setScreen(&updateFWConnectedScreen);
          break;
        case 1:
          setScreen(&updateFWDownloadingScreen);
          break;
        case 2:
          setScreen(&updateFWDownloadCompleteScreen);
          delay(2000);
          esp_restart();  // does not return
        case 4:
          setScreen(&updateFWDisconnectedScreen);
          delay(1000);

          // turn off radios
          WiFi.mode(WIFI_OFF);
          btStop();
          setScreen(&menuScreen);
          return;
        default:
          break;
      }
      prevStatus = currentStatus;
      delay(100);  // feed the watchdog
    } else if (prevStatus == 1) {
      showWatchFace(true);
      delay(1000); // update progress every 1 sec
    }
    yield();
  }
}

class : public Screen {
  void show() {
    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(0, 30);
    display.println("Bluetooth Started");
    display.println();
    display.println("Watchy BLE OTA");
    display.println();
    display.println("Waiting for");
    display.println("connection...");

    btPoll();
  }
} updateFWBeginScreen;

void UpdateFWScreen::show() {
  display.setFont(&FreeMonoBold9pt7b);
  display.setCursor(0, 30);
  display.println("Please Visit");
  display.println("watchy.sqfmi.com");
  display.println("with a Bluetooth");
  display.println("enabled device");
  display.println();
  display.println("Press menu button");
  display.println("again when ready");
  display.println();
  display.println("Keep USB powered");

  BLE BT;
}
void UpdateFWScreen::back() { setScreen(&menuScreen); }
void UpdateFWScreen::menu() { setScreen(&updateFWBeginScreen); }