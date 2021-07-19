#include "SetupWifiScreen.h"

#include "MenuScreen.h"
#include "Screen.h"
#include "Watchy.h"

using namespace Watchy;

SetupWifiScreen setupWifiScreen;

class : public Screen {  // waitingForConfigScreen
  void show() {
    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(0, 30);
    display.println("Connect to");
    display.print("SSID: ");
    display.println(WIFI_AP_SSID);
    display.print("IP: ");
    display.println(WiFi.softAPIP());
  }
  void up() { setScreen(&menuScreen); }
  void down() { setScreen(&menuScreen); }
  void back() { setScreen(&menuScreen); }
  void menu() { setScreen(&menuScreen); }
} waitingForConfigScreen;

class : public Screen {  // wifiSetupFailedScreen
  void show() {
    display.setFont(&FreeMonoBold9pt7b);
    display.setCursor(0, 30);
    display.println("Wifi setup");
    display.println("failed");
    display.println("Connection");
    display.println("timed out!");
    display.println("press any button");
    display.println("to return to menu");
  }
  void up() { setScreen(&menuScreen); }
  void down() { setScreen(&menuScreen); }
  void back() { setScreen(&menuScreen); }
  void menu() { setScreen(&menuScreen); }
} wifiSetupFailedScreen;

class : public Screen {  // wifiSetupSuccessScreen
  void show() {
    display.setFont(&FreeMonoBold9pt7b);
    display.println("Wifi setup");
    display.println("succeeded");
    if (WIFI_CONFIGURED) {
      display.println("Connected to");
      display.println(WiFi.SSID());
    }
    display.println("press any button");
    display.println("to return to menu");
  }
  void up() { setScreen(&menuScreen); }
  void down() { setScreen(&menuScreen); }
  void back() { setScreen(&menuScreen); }
  void menu() { setScreen(&menuScreen); }
} wifiSetupSuccessScreen;

const int WIFI_AP_TIMEOUT = 60;

void _configModeCallback(WiFiManager *myWiFiManager);

void SetupWifiScreen::show() {
  // the actual show happens in _configModeCallback
  WiFiManager wifiManager;
  wifiManager.resetSettings();
  wifiManager.setTimeout(WIFI_AP_TIMEOUT);
  wifiManager.setAPCallback(_configModeCallback);
  if (!wifiManager.autoConnect(WIFI_AP_SSID)) {
    WIFI_CONFIGURED = false;
    setScreen(&wifiSetupFailedScreen);
  } else {
    WIFI_CONFIGURED = true;
    setScreen(&wifiSetupSuccessScreen);
  }
  // turn off radios
  WIFI_CONFIGURED = false;
  WiFi.mode(WIFI_OFF);
  btStop();
}

void _configModeCallback(WiFiManager *myWiFiManager) {
  setScreen(&waitingForConfigScreen);
}