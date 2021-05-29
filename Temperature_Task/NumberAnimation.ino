
#include "M5Atom.h"
#include "math.h"

bool IMU6886Flag = false;

//Links all LED data for each number and symbol
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

//sets value of temperature, to be changed once temperature is actually read
float temp;

void setup()
{
    M5.begin(true, false, true);
    M5.IMU.Init();
    //delay(10);
   
}

//ensures code is only run once
int ctr = 0;
double start, finished, elapsed;

void loop()
{
  //declare values for units in tens and ones place
  int TempTens = 0;
  int TempOnes = 0;
  int Temp = temp;

  M5.IMU.getTempData(&temp);
  Serial.print("The temperature is ");
  Serial.println(temp);    // print the number
  start=millis();
  delay(10000);
  finished=millis();
  elapsed=(finished-start)/1000.000;
  Serial.print(elapsed);
  Serial.println(" seconds elapsed");
  
//  if (ctr < 1)
//  {
      //check if number is negative
      if(Temp < 0)
      {
            //display negative sign before value
            M5.dis.animation((uint8_t *)image_negative, 150, LED_DisPlay::kMoveLeft, 20);
            delay(750);
            M5.update();
            Temp = Temp * -1; //turn to positive value for numeral detection
      }

      //determine number in the tens place
      TempTens = (Temp / 10) % 10;

      //display number in the tens place
      switch(TempTens)
      {
        case 0:
        {
            //if less than 10, display nothing
            break;
        }

        case 1: //display 1
        {
            M5.dis.animation((uint8_t *)image_num1B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(750);
            M5.update();
            break;
        }
        case 2: //display 2
        {
            M5.dis.animation((uint8_t *)image_num2B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(750);
            M5.update();
            break;
        }
        case 3: //display 3
        {
            M5.dis.animation((uint8_t *)image_num3B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(750);
            M5.update();
            break;
        }
        case 4: //display 4
        {
            M5.dis.animation((uint8_t *)image_num4B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(750);
            M5.update();
            break;
        }
        case 5: //display 5
        {
            M5.dis.animation((uint8_t *)image_num5B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(750);
            M5.update();
            break;
        }
        case 6: //display 6
        {
            M5.dis.animation((uint8_t *)image_num6B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(750);
            M5.update();
            break;
        }
        case 7: //display 7
        {
            M5.dis.animation((uint8_t *)image_num7B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(750);
            M5.update();
            break;
        }
        case 8: //display 8
        {
            M5.dis.animation((uint8_t *)image_num8B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(750);
            M5.update();
            break;
        }
        case 9: //display 9
        {
            M5.dis.animation((uint8_t *)image_num9B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(750);
            M5.update();
            break;
        }
      }

      //determine number in the ones place
      TempOnes = Temp - (TempTens * 10);

      //display number in the ones place
      switch(TempOnes)
      {
        case 0: //display 0
        {
            M5.dis.animation((uint8_t *)image_num0B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(850);
            M5.update();
            break;
        }

        case 1: //display 1
        {
            M5.dis.animation((uint8_t *)image_num1B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(850);
            M5.update();
            break;
        }
        case 2: //display 2
        {
            M5.dis.animation((uint8_t *)image_num2B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(850);
            M5.update();
            break;
        }
        case 3: //display 3
        {
            M5.dis.animation((uint8_t *)image_num3B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(850);
            M5.update();
            break;
        }
        case 4: //display 4
        {
            M5.dis.animation((uint8_t *)image_num4B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(850);
            M5.update();
            break;
        }
        case 5: //display 5
        {
            M5.dis.animation((uint8_t *)image_num5B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(850);
            M5.update();
            break;
        }
        case 6: //display 6
        {
            M5.dis.animation((uint8_t *)image_num6B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(850);
            M5.update();
            break;
        }
        case 7: //display 7
        {
            M5.dis.animation((uint8_t *)image_num7B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(850);
            M5.update();
            break;
        }
        case 8: //display 8
        {
            M5.dis.animation((uint8_t *)image_num8B, 150, LED_DisPlay::kMoveLeft, 20);
            delay(850);
            M5.update();
            break;
        }
        case 9: //display 9
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

      //display the unit (celsius)
      M5.dis.animation((uint8_t *)image_degree, 150, LED_DisPlay::kMoveLeft, 20);
      delay(1000);
      M5.update();


  //increment counter
//  ctr++;
//  }

  //clear display when done
  M5.dis.clear();
  delay(500);
  M5.update();

}
