# Watchy Screen Demo

This is a [Watchy](https://watchy.sqfmi.com/) watchface based on [Watchy-Screen](https://github.com/charles-haynes/Watchy-Screen) intended to demonstrate a multi-screen watchface.

## Screens

It includes individual screens for:

* Time/Date  
* Weather  
* Battery  
* Bluetooth Status
* Orientation
* Set Time - Set the current time and date
* Setup Wifi - Sets up Wifi credentials
* Update Firmware - Update the watch firmware Over-The-Air via bluetooth
* Number of Steps
* Wifi Status

And two "aggregate" screens used to organize other screens:

* Menu - Simple text menu.
* Carousel - A list of "splash" screens and their corresponding display screens.

## UI

### Menu

The menu screen implements a simple text menu. It takes an array of menu items, each consisting of a textual menu item name and corresponding screen to invoke. `up` and `down` navigate the menu, `menu` invokes the current item. When in a menu item's screen `back` takes you back to the menu.

### Carousel

The carousel implements a cyclic view of spash screens and a corresponding display. Typically a splash screen is a simple static graphical or textual screen, and a display screen has more complex active logic.

While in a carousel `up` takes you to the previous splash screen, `down` takes you to the next one, `menu` shows the display screen for that splash screen, `back` while looking at a splash screen takes you back to the first screen of the carousel. When in a display screen `back` takes you back to it's splash screen. If the splash screen contains all information for the display the display screen can be null.

## Demo

The face is organized as a carousel of time, weather, battery, steps, orientation, bluetooth status, weather status, and a settings menu. The time and weather screens are standalone, they don't have a display associated.

The settings display screen is a menu that lets you set the time, setup the wifi, or update the firmware.

There are no dependencies within the screens, all of the screen instances and their organization are in `main.cpp` most of the screens are just a `show` method.
