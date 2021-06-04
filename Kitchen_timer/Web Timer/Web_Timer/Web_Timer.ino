/*
  WiFiAccessPoint.ino creates a WiFi access point and provides a web server on it.

  Steps:
  1. Connect to the access point "yourAp"
  2. Point your web browser to http://192.168.4.1/H to turn the LED on or http://192.168.4.1/L to turn it off
     OR
     Run raw TCP "GET /H" and "GET /L" on PuTTY terminal with 192.168.4.1 as IP address and 80 as port

  Created for arduino-esp32 on 04 July, 2018
  by Elochukwu Ifediora (fedy0)
*/
#include "M5Atom.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

#define LED_BUILTIN 2   // Set the GPIO pin where you connected your test LED or comment this line out if your dev board has a built-in LED

// Set these to your desired credentials.
const char *ssid = "Team7";
const char *password = "assignment2";

WiFiServer server(80);

double start, finished, elapsed;
unsigned long intervalTime = 0;
unsigned long intervalTime1 = 0;
unsigned long intervalTimeDisplay = 0;
bool resetInterval = false;

bool timerSet1 = false;
bool timeSelect = false;

//FOR TIMER 1
int hourTimer1 = 0;
int minuteTimer1 = 1;
int secondTimer1 = 0;
double totalTime1 = 0;
double fracTime1 = 0;

bool hourloop = false;
bool minuteloop = false;
bool secondloop = false;


//double currentTime, lastUpdateTime, elapsed;
unsigned long currentTime=0;

void delayInterval(int num)
{ 
  currentTime=millis();
  while(millis()<(currentTime+num))
   {
      //do nothing
   }
}

bool resetInterval1 = false;


//void countdown(int &seconds, int &minutes, int &hours)
//{
//  if(resetInterval == false)
//  {
//    intervalTime = 0;
//    intervalTime = millis();
//    resetInterval = true;
//  }
//  
//  if(millis() >= intervalTime + 1000) //1 second timer
//  {
//    if(seconds >= 0) //for every second
//    {
//      seconds--;
//    }
//
//    if(seconds < 0 && minutes == 0 && hours > 0) //for every hour
//    {
//      hours--;
//      minutes = 59;
//      seconds = 59;
//    }
//    
//    if(seconds < 0 && minutes > 0) //for every minute
//    {
//      minutes--;
//      seconds = 59;
//    }
//
//    
//    else if(seconds < 0 && minutes == 0 && hours == 0) //when the timer reaches 0
//    {
//      bool snoozeTimer = false;
//      while(snoozeTimer == false)
//      {
//      M5.dis.fillpix(0xFFFFFF);
//      delayInterval(500);
//      M5.update();
//
//      M5.dis.clear();
//      delayInterval(500);
//      M5.update();
//
//      if(M5.Btn.wasPressed())
//      {
//        snoozeTimer = true;
//      }
//      }
//    }
//    resetInterval = false;
//  }
//}


void setup() {

  Serial.begin(115200);
  Serial.println();
  Serial.println("Configuring access point...");

  // You can remove the password parameter if you want the AP to be open.
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Server started");
}

bool newTime1 = false, newTime2 = false;
int secondsTest = 0;

void loop() {

//  countdown(secondTimer1, minuteTimer1, hourTimer1);
  
  WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        //Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("<body> <p>Timer 1:</p> <style> p { text-align: center; font-size: 60px; margin-top: 0px; } </style> </head> <body> <p id='demo'></p> <div class='Timer1+'> <button onclick='add10hr1()'>+10 h</button> <button onclick='add1hr1()'>+1 h</button> <button onclick='add10min1()'>+10 m</button> <button onclick='add1min1()'>+1 m</button> <button onclick='add10sec1()'>+10 s</button> <button onclick='add1sec1()'>+1 s</button> </div> <div class='Timer1-'> <button onclick='del10hr1()'>-10 h</button> <button onclick='del1hr1()'>-1 h</button> <button onclick='del10min1()'>-10 m</button> <button onclick='del1min1()'>-1 m</button> <button onclick='del10sec1()'>-10 s</button> <button onclick='del1sec1()'>-1 s</button> </div> <button onclick='startTimer1()'>Start Timer</button> <script> var seconds1 = 0; var minutes1 = 0; var hours1 = 0; var timer1On = false; var totalTime1 = 0; function add1sec1() { seconds1 = seconds1 + 1; } function add10sec1() { seconds1 = seconds1 + 10; } function del1sec1() { seconds1 = seconds1 - 1; } function del10sec1() { seconds1 = seconds1 - 10; } function add1min1() { minutes1 = minutes1 + 1; } function add10min1() { minutes1 = minutes1 + 10; } function del1min1() { minutes1 = minutes1 - 1; } function del10min1() { minutes1 = minutes1 - 10; } function add1hr1() { hours1 = hours1 + 1; } function add10hr1() { hours1 = hours1 + 10; } function del1hr1() { hours1 = hours1 - 1; } function del10hr1() { hours1 = hours1 - 10; } function startTimer1() { timer1On = true; totalTime1 = 69; return totalTime1; } setInterval(function() { document.getElementById('demo').innerHTML = hours1 + 'h ' + minutes1 + 'm ' + seconds1 + 's '; if(timer1On) { if(seconds1 >= 0) { seconds1 = seconds1 - 1; } if(seconds1 < 0 && minutes1 == 0 && hours1 > 0) { hours1 = hours1 - 1; minutes1 = 59; seconds1 = 59; } if(seconds1 < 0 && minutes1 > 0) { minutes1 = minutes1 -1; seconds1 = 59; } else if(seconds1 < 0 && minutes1 == 0 && hours1 == 0) { seconds1 = 0; timer1On = false; } } else { if(seconds1 < 0) { seconds1 = 0;} if(minutes1 < 0) { minutes1 = 0;} if(hours1 < 0) { hours1 = 0;} if(seconds1 > 59) { seconds1 = 59;} if(minutes1 > 59) { minutes1 = 59;} } }, 1000); </script> </body>");
            Serial.println("Seconds is: ");
            totalTime1 = client.print("<script> return totalTime1; </script>");
            Serial.print(totalTime1);
            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
//        if (currentLine.endsWith("GET /H")) {
//          //INTERESTING PART 2
//          Serial.println("I AM HIGH");
//        }
//        if (currentLine.endsWith("GET /L")) {
//          //INTERESTING PART 3
//          Serial.println("I AM LOW");
//
//        }
      }

      
    }
    // close the connection:
//    client.stop();
//    Serial.println("Client Disconnected.");
  }
}
