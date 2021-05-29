#include "M5Atom.h"

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
extern const unsigned char image_negative[122];
extern const unsigned char image_degree[152];

void setup()
{
    M5.begin(true, false, true);
    //delay(10);
   
}

uint8_t ctr = 0;

void loop()
{
  //run the code once
  if (ctr < 1)
  {
  
  //Show the tens number
  M5.dis.animation((uint8_t *)image_num4B, 150, LED_DisPlay::kMoveLeft, 20);
  delay(750); //length of animation ––DONT CHANGE––
  M5.update();

  //Show the ones number
  M5.dis.animation((uint8_t *)image_num3B, 150, LED_DisPlay::kMoveLeft, 20);
  delay(850); //length of animation ––DONT CHANGE––
  M5.update();

  //Show the unit (celcius)
  M5.dis.animation((uint8_t *)image_degree, 150, LED_DisPlay::kMoveLeft, 20);
  delay(1000); //length of animation ––DONT CHANGE––
  M5.update();


  
  ctr++;
  }
  M5.dis.clear();
  delay(500);
  M5.update();

}
