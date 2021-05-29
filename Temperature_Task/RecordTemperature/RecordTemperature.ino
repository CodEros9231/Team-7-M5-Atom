
#include "M5Atom.h"

float temp;


void setup()
{ //Serial.clear();
  M5.begin();
  M5.IMU.Init();
  Serial.begin(9600); // send and receive at 9600 baud
}
double start, finished, elapsed;

void loop()
{M5.IMU.getTempData(&temp);
Serial.print("The temperature is ");
  Serial.println(temp);    // print the number
start=millis();
  delay(10000);
finished=millis();
elapsed=(finished-start)/1000.000;
Serial.print(elapsed);
Serial.println(" seconds elapsed");
  
}
