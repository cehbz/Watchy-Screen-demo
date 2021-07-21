#include "SetupWifiScreen.h"

#include "MenuScreen.h"
#include "Screen.h"
#include "Watchy.h"

using namespace Watchy;

class : public Screen {  // waitingForConfigScreen
  void show() override {
    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(0, 30);
    display.println("Connect to");
    display.print("SSID: ");
    display.println(WIFI_AP_SSID);
    display.print("IP: ");
    display.println(WiFi.softAPIP());
  }
} waitingForConfigScreen;

class : public Screen {  // wifiSetupFailedScreen
  void show() override {
    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(0, 30);
    display.println("Wifi setup");
    display.println("failed");
    display.println("Connection");
    display.println("timed out!");
    display.println("press back");
    display.println("to return to menu");
  }
} wifiSetupFailedScreen;

class : public Screen {  // wifiSetupSuccessScreen
  void show() override {
    display.setFont(&FreeMonoBold9pt7b);
    display.println("Wifi setup");
    display.println("succeeded");
    if (WIFI_CONFIGURED) {
      display.println("Connected to");
      display.println(WiFi.SSID());
    }
    display.println("press back");
    display.println("to return to menu");
  }
} wifiSetupSuccessScreen;

const int WIFI_AP_TIMEOUT = 60;

void _configModeCallback(WiFiManager *myWiFiManager);

// implement this show as a state machine with three states
// waiting for setup
// success
// failure
void SetupWifiScreen::show() {
  // the actual show happens in _configModeCallback
  WiFiManager wifiManager;
  wifiManager.resetSettings();
  wifiManager.setTimeout(WIFI_AP_TIMEOUT);
  wifiManager.setAPCallback(_configModeCallback);
  if (!wifiManager.autoConnect(WIFI_AP_SSID)) {
    WIFI_CONFIGURED = false;
    setScreen(&wifiSetupFailedScreen);  // BUG, we're a child. Setting the
                                        // screen will forget our parent
  } else {
    WIFI_CONFIGURED = true;
    setScreen(&wifiSetupSuccessScreen);  // BUG, we're a child. Setting the
                                         // screen will forget our parent
  }
  // turn off radios
  WIFI_CONFIGURED = false;
  WiFi.mode(WIFI_OFF);
  btStop();
}

void _configModeCallback(WiFiManager *myWiFiManager) {
  setScreen(&waitingForConfigScreen);  // BUG, we're a child. Setting the screen
                                       // will forget our parent
}