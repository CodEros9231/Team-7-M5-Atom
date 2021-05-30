
#include "M5Atom.h"

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
float temp = 0;
int Temp = 0;

int ctr = 0;

double start, finished, elapsed;


//reads the temperature at a given interval
float readTemp()
{
    M5.IMU.getTempData(&temp);
    Serial.print("The temperature is ");
    Serial.println(temp);    // print the number
    start=millis();
    delay(3000);
    finished=millis();
    elapsed=(finished-start)/1000.000;
    Serial.print(elapsed);
    Serial.println(" seconds elapsed");
    return temp;
}

//check if temperature value is negative
void checkNegative(int tempValue)
{
    //check if number is negative
    if(tempValue < 0)
    {
    //display negative sign before value
    M5.dis.animation((uint8_t *)image_negative, 150, LED_DisPlay::kMoveLeft, 20);
    delay(750);
    M5.update();
    }
}

//change negative temp value to positive
int changeNegative (int &Temp)
{
  if(Temp < 0)
    {
      Temp = Temp * -1; //turn to positive value for numeral detection
    }
}

//displays the unit in the tens place
void displayTens(int &TempTens, int Temp)
{
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
}

//displays the unit in the ones place
void displayOnes(int TempTens, int Temp, int &TempOnes)
{
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
}



void setup()
{
    M5.begin(true, false, true);
    M5.IMU.Init();
    //delay(10);
   
}

void loop()
{

  //indicates 1 loop
  //Turn all LEDs on to White
//  M5.dis.fillpix(0xFFFFFF);
//  M5.update();
//  delay(200); //interval of 200 ms
//
//  //Turn all LEDs off
//  M5.dis.clear();
//  M5.update();
//  delay(200);
  
  if (M5.Btn.wasPressed()) //if button pressed
    {
      ctr++; //increment counter
        if (ctr >= 5) //if counter exceeds number of states
        {
            ctr = 0; //reset counter
        }
        M5.dis.clear(); //clear LEDs
            M5.update(); //update
            delay(50);
    }

  Serial.println(ctr); //prints counter of button presses
  delay(500);

  
  
  //declare values for units in tens and ones place
  int TempTens = 0;
  int TempOnes = 0;
  int Temp = readTemp();

     //Switch case for the current state of the LEDs
     switch (ctr)
        {
        case 0: //Show Active Temperature + Units
        {
            //check if number is negative
            checkNegative(Temp);
            changeNegative(Temp);

            //display the number in the tens place
            displayTens(TempTens, Temp);

            //display number in the ones place
            displayOnes(TempTens, Temp, TempOnes);
      
            //display the unit (celsius)
            M5.dis.animation((uint8_t *)image_degree, 150, LED_DisPlay::kMoveLeft, 20);
            delay(1000);
            M5.update();
      
            break;
        }
        
        case 1: //Show average of last 24 hours of temperature + Units
        {
            
            break;
        }
        
        case 2: //Show color scale of temperature range + current temperature as color
        {
            
            break;
        }
        
        case 3: //Show graph of temperature across a predefined range.
        {
            
            break;
        }
        
        case 4: //Change units
        {
            
            break;
        }

        default: //default case
            break; //exit loop
        }

//–––––––––––––––––––––––––––––––––  

 

  //clear display when done
  M5.dis.clear();
  delay(500);
  M5.update();

}
