TEAM 7: DESIGN AND INNOVATION Jason Cruz, Tala Alouf, Eros Kuikel, Ma-sum Abdul-Hamid

PART I.2: Temperature Sensor

This code serves as a multi-purpose thermometer and temperature tracker, made to work with the M5Stack Atom Matrix.

It has 6 modes:
  1. Display Off, with temperature recording occurring in the background. While the display is off, it records temperature at a pre-determined interval (in our case, every 10 minutes)
  2. Shows the active/current temperature with units
  3. Shows the average temperature over the past 24 hours with units
  4. Shows a color scale of temperature ranges and the current temperature as a color
  5. Shows a graph of temperature values acrosss a predefined range
  6. Changes the unit from either Celsius or Fahrenheit
  
While the display is off, the screen can be activated by facing the atom upwards, or by tapping/clicking the button on the screen.
Modes can be changed by cycling through the menu by tilting left or right. This is made possible by the MPU6886 that measures pitch and roll.
The display can be deactivated by turning the device face down.

There are a few assumptions with the device, including:
  • Assume the device is carried with an individual throughout the day.
  • Assume power is already available (not your responsibility to imagine how to install a battery in the design) 
  
This code requires the "M5Atom.h" and "FastLED.h" libraries to be installed.  
