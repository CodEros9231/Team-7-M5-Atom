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

extern const unsigned char image_num0B[122];
extern const unsigned char image_num1B[122];
extern const unsigned char image_num2B[122];
extern const unsigned char image_num3B[122];
extern const unsigned char image_num4B[122];
extern const unsigned char image_num5B[122];
extern const unsigned char image_num6B[122];
extern const unsigned char image_num7B[122];
extern const unsigned char image_num8B[122];
extern const unsigned char image_num9B[122];
extern const unsigned char image_degree[152];

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
//  M5.dis.animation((uint8_t *)image_num40, 200, LED_DisPlay::kMoveLeft, 20);
  M5.dis.animation((uint8_t *)image_num4B, 150, LED_DisPlay::kMoveLeft, 20);
  delay(750);
  M5.update();
//  M5.dis.clear();
  M5.dis.animation((uint8_t *)image_num3B, 150, LED_DisPlay::kMoveLeft, 20);
  delay(850);
  M5.update();
  M5.dis.animation((uint8_t *)image_degree, 150, LED_DisPlay::kMoveLeft, 20);
  delay(1000);
  M5.update();


  
  FSM++;
  }
  M5.dis.clear();
  delay(500);
  M5.update();

}
