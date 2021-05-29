
#include "M5Atom.h"
#include "math.h"

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
extern const unsigned char image_negative[122];

int Temp = -21;

void setup()
{
    M5.begin(true, false, true);
    //delay(10);
   
}

int FSM = 0;

void loop()
{

  uint8_t TempTens = 0;
  uint8_t TempOnes = 0;
  
  if (FSM < 1)
  {
      if(Temp < 0)
      {
            M5.dis.animation((uint8_t *)image_negative, 150, LED_DisPlay::kMoveLeft, 20);
            delay(750);
            M5.update();
            Temp = Temp * -1;
      }

      
      TempTens = (Temp / 10) % 10;
      
      switch(TempTens)
      {
        case 0:
        {
            break;
        }

        case 1:
        {
            M5.dis.animation((uint8_t *)image_num1B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(750);
            M5.update();
            break;
        }
        case 2:
        {
            M5.dis.animation((uint8_t *)image_num2B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(750);
            M5.update();
            break;
        }
        case 3:
        {
            M5.dis.animation((uint8_t *)image_num3B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(750);
            M5.update();
            break;
        }
        case 4:
        {
            M5.dis.animation((uint8_t *)image_num4B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(750);
            M5.update();
            break;
        }
        case 5:
        {
            M5.dis.animation((uint8_t *)image_num5B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(750);
            M5.update();
            break;
        }
        case 6:
        {
            M5.dis.animation((uint8_t *)image_num6B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(750);
            M5.update();
            break;
        }
        case 7:
        {
            M5.dis.animation((uint8_t *)image_num7B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(750);
            M5.update();
            break;
        }
        case 8:
        {
            M5.dis.animation((uint8_t *)image_num8B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(750);
            M5.update();
            break;
        }
        case 9:
        {
            M5.dis.animation((uint8_t *)image_num9B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(750);
            M5.update();
            break;
        }
      }

      TempOnes = Temp - (TempTens * 10);
      
      switch(TempOnes)
      {
        case 0:
        {
            M5.dis.animation((uint8_t *)image_num0B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(850);
            M5.update();
            break;
        }

        case 1:
        {
            M5.dis.animation((uint8_t *)image_num1B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(850);
            M5.update();
            break;
        }
        case 2:
        {
            M5.dis.animation((uint8_t *)image_num2B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(850);
            M5.update();
            break;
        }
        case 3:
        {
            M5.dis.animation((uint8_t *)image_num3B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(850);
            M5.update();
            break;
        }
        case 4:
        {
            M5.dis.animation((uint8_t *)image_num4B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(850);
            M5.update();
            break;
        }
        case 5:
        {
            M5.dis.animation((uint8_t *)image_num5B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(850);
            M5.update();
            break;
        }
        case 6:
        {
            M5.dis.animation((uint8_t *)image_num6B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(850);
            M5.update();
            break;
        }
        case 7:
        {
            M5.dis.animation((uint8_t *)image_num7B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(850);
            M5.update();
            break;
        }
        case 8:
        {
            M5.dis.animation((uint8_t *)image_num8B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(850);
            M5.update();
            break;
        }
        case 9:
        {
            M5.dis.animation((uint8_t *)image_num9B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(850);
            M5.update();
            break;
        }
      }

      
//      M5.dis.animation((uint8_t *)image_num4B, 150, LED_DisPlay::kMoveLeft, 20);
//      delay(750);
//      M5.update();
//      M5.dis.animation((uint8_t *)image_num3B, 150, LED_DisPlay::kMoveLeft, 20);
//      delay(850);
//      M5.update();
      M5.dis.animation((uint8_t *)image_degree, 150, LED_DisPlay::kMoveLeft, 20);
      delay(1000);
      M5.update();


  
  FSM++;
  }
  M5.dis.clear();
  delay(500);
  M5.update();

}
