/****************************************************************
 * 
 * This Example is used to test button
 * 
 * Arduino tools Setting 
 * -board : M5StickC
 * -Upload Speed: 115200 / 750000 / 1500000
 * 
****************************************************************/

#include "M5Atom.h"

bool IMU6886Flag = false;

extern const unsigned char image_num1[77];
//extern const unsigned char image_num2[77];

void setup()
{
    M5.begin(true, false, true);
    //delay(10);
   
}

uint8_t FSM = 0;

void loop()
{

  if (FSM < 1)
  {
  M5.dis.animation((uint8_t *)image_num1, 200, LED_DisPlay::kMoveLeft, 0);
  delay(500);
  M5.update();
  M5.dis.clear();
//  M5.dis.animation((uint8_t *)image_num2, 500, LED_DisPlay::kMoveLeft, 100);
//  delay(500);
//  M5.update();
  FSM++;
  }
  M5.dis.clear();
  delay(500);
  M5.update();

}
