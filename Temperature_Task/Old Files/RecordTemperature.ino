
#include "M5Atom.h"

float temp;


void setup()
{ //Serial.clear();
  M5.begin();
  M5.IMU.Init();
  Serial.begin(9600); // send and receive at 9600 baud
}

int number = 0;

void loop()
{M5.IMU.getTempData(&temp);
  Serial.print("The temperature is ");
  Serial.println(temp);    // print the number

  delay(500); // delay half second between numbers
  number++; // to the next number
}
