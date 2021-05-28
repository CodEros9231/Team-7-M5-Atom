#include "M5Atom.h"

bool IMU6886Flag = false;



void setup() {
  M5.begin(true, false, true); //sets LED board
  if (!M5.IMU.Init()) IMU6886Flag = true; //sets flag to true
}


void loop() {

  //opens red LED at center
  M5.dis.drawpix(12, 0x00F000); 
  M5.update();
  delay(50);

  //determines acceleration values in x, y, z directions
  float accX = 0, accY = 0, accZ = 0;
  if (IMU6886Flag == true) {
    M5.IMU.getAccelData(&accX, &accY, &accZ);
  }

  //prints acceleration values on Serial Monitor
  //Serial.println(accX);
  //delay(500);

  //turns off LED when threshold reached
  if(accX >= 1 || accX <= -1)
  {
    M5.dis.drawpix(12, 0x000000);
    M5.update();
    delay(50);
  }
  
  M5.update();
}
