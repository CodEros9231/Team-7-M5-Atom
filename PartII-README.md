TEAM 7: DESIGN AND INNOVATION Jason Cruz, Tala Alouf, Eros Kuikel, Ma-sum Abdul-Hamid

PART II: Kitchen Timer

This code serves as a Kitchen Timer that works both with the M5 Stack Atom Matrix and on a Web Browser that can be accessed via a wifi network from the Atom. The device allows for 2 Timers to count down simultaneously. It can be set and viewed with both the M5 Stack Atom and Webpage.

The M5 Stack Atom is designed to be housed in a casing, along with a PCB and Battery which comprises the physical timer.

SETTING TIME ON THE ATOM:

When using the M5 Stack Atom device, the display is off by default. It can be turned on by turning the timer face up or clicking the screen.
Once on, the user is presented with an interface with the following options:
  1. Timer 1
  2. Timer 2

The user can tilt the device to the left or right to scroll through these options.

If no times have been set yet, clicking on a timer option brings the user to another interface with these options when clicked:
  H: Allows the user to set the number of hours to count down to
  M: Allows minutes to be set
  S: Allows seconds to be set
  ✓: Confirms the time selection and begins the timer
  
The quantity of time can be added or subtracted by tilting the screen right or left respectively. To confirm the selection, the user must point the timer face-forward until they are returned to the H:M:S menu.

Once a time has been set, the Atom starts counting down automatically and returns to the Timer selection menu. If a timer is selected and it is currently counting down, the Atom displays a countdown timer that decreases anti-clockwise. Clicking the screen returns the user back to the TImer selection menu.
Each timer can be differentiated by their color:
  Timer 1: GREEN
  Timer 2: RED
  
When the timer reaches zero, the Atom screen flashes until the user clicks the button to reset the timer.

*Note: Starting the timer on the webpage also starts the timer on the Atom. When selecting a timer, the display will show the countdown after the timer was set.


SETTING TIME ON THE WEBPAGE:

When using the webpage, the user is presented with two timers that display hours, minutes, and seconds (by default they are at 0). Timer 1 and 2 are still distinguished by the colors mentioned previously.
There are6 buttons that allow the user to add or subtract time: a +1 and -1 for hours, minutes, and seconds. Their desired time is displayed in a smaller font above the buttons before confirmation. Once the time is confirmed, the user can click the "Set Timer" button in order to start the timer. This activates the timer and the countdown is displayed.

*Note: Starting the timer on the Atom also starts the timer on the webpage. The input values for hours, minutes, and seconds are updated automatically.



WIFI Setup: In order to use the webpage, you must be connected to the WifiAP created by the Atom.
  
  Wifi SSID: Team7
  
  Password: assignment2
  
  To access the webpage, type this address into the browser: 192.168.4.1

This code must be run with the "combinedcode.io" file, which is attached to two other files: a .c file containing all the images used to display on the Atom, and a header file containing the HTML, CSS, and JavaScript code used for the website.

This code requires the following libraries to be installed:
  1. M5Atom
  2. FastLED
  3. Wifi
  4. WifiClient
  5. WebServer
  6. ESPmDNS
