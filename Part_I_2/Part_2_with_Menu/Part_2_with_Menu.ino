#include "M5Atom.h"
#define NUM_LEDS 160
CRGB leds[ NUM_LEDS ];
extern const unsigned char image_num1W[77];
extern const unsigned char image_num2W[77];
extern const unsigned char image_num3W[77];
extern const unsigned char image_num4W[77];
extern const unsigned char image_num5W[77];
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
extern const unsigned char image_degreeF[137];
extern const unsigned char image_degreeCW[77];
extern const unsigned char image_degreeFW[137];
extern const unsigned char image_negative[122];
extern const unsigned char image_smallercolorscale[77];
bool IMU6886Flag =false, atomState=false,modeState=false;
int counterArray=0,optionsCTR=0;
double graphTemp[6],start, finished, elapsed,pitch, roll;

//sets value of temperature, to be changed once temperature is actually read
double temp = 0;
double Temp = 0;
double TempArray[8640];
double SumofTemp=0;
double AveTemp = 0;

float currentTemp = 0;
double averageTemp = 0;

unsigned long intervalTime = 0;
bool resetInterval = false;


int ctr = 0;
int tempCounts=0;

//declare values for units in tens and ones place
int TempTens = 0;
int TempOnes = 0;

int unitCTR = 0;
bool isCelsius = true;

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

//reads the temperature at a given interval
void readTemp()
{
  if(resetInterval == false)
  {
    intervalTime = 0;
    intervalTime = millis();
    resetInterval = true;
  }
  
  if(millis() >= intervalTime + 5000) //trial with 5 seconds, replace with 600,000 for 10 minutes
  {
    M5.IMU.getTempData(&currentTemp);
    Serial.print("The temperature is ");
    Serial.println(currentTemp);    // print the temperature value
    TempArray[tempCounts] = currentTemp;
    //if (tempCounts % 5 ==0)
    {//filling the graphTempArray with latest
      graphTemp[counterArray]=currentTemp;
      counterArray++;
      if (counterArray>=6)//replacing the values one by one
      {counterArray=0;
      graphTemp[0]=graphTemp[1];
      graphTemp[1]=graphTemp[2];
      graphTemp[2]=graphTemp[3];
      graphTemp[3]=graphTemp[4];
      graphTemp[4]=graphTemp[5];
      
      
        }
      }
    
    SumofTemp += currentTemp;
    tempCounts++;

    averageTemp = SumofTemp / tempCounts;
    
    Serial.print("The average temperature is ");
    Serial.println(averageTemp);    // print the average temperature value

    if (tempCounts >= 8640)
    {
        SumofTemp=SumofTemp-TempArray[0];
        tempCounts=0;
    }

    resetInterval = false;
    
  }
}

float convertF(float Temp)
{
  float ftemp = 0;
  ftemp = ((9 * Temp) / 5) + 32;
  Serial.print("The temperature in fahrenheit is ");
  Serial.println(ftemp);    // print the average temperature value
  return ftemp;
}

//check if temperature value is negative
void checkNegative(int tempValue)
{
    //check if number is negative
    if(tempValue < 0)
    {
    //display negative sign before value
    M5.dis.animation((uint8_t *)image_negative, 150, LED_DisPlay::kMoveLeft, 20);
    delayInterval(750);
    M5.update();
    }
}
//displays the unit in the tens place
void displayTens(int &TempTens, int Temp)
{
          if(isCelsius == false)
          {
            if(Temp >= 100)
            {
              M5.dis.animation((uint8_t *)image_num1B, 150, LED_DisPlay::kMoveLeft, 20);
              delayInterval(750);
              M5.update();
              Temp = Temp - 100;
            }
          }
          
          //determine number in the tens place
            TempTens = (Temp / 10) % 10;

            //display number in the tens place
            switch(TempTens)
            {
              case 0:
              {
                  //if less than 10, display nothing
                  if(isCelsius == false)
                  {
                    M5.dis.animation((uint8_t *)image_num0B, 150, LED_DisPlay::kMoveLeft, 20);
                  }
                  break;
              }

              case 1: //display 1
              {
                  M5.dis.animation((uint8_t *)image_num1B, 150, LED_DisPlay::kMoveLeft, 20);
                  
                  break;
              }
              case 2: //display 2
              {
                  M5.dis.animation((uint8_t *)image_num2B, 150, LED_DisPlay::kMoveLeft, 20);
                  
                  break;
              }
              case 3: //display 3
              {
                  M5.dis.animation((uint8_t *)image_num3B, 150, LED_DisPlay::kMoveLeft, 20);
                  
                  break;
              }
              case 4: //display 4
              {
                  M5.dis.animation((uint8_t *)image_num4B, 150, LED_DisPlay::kMoveLeft, 20);
                 
                  break;
              }
              case 5: //display 5
              {
                  M5.dis.animation((uint8_t *)image_num5B, 150, LED_DisPlay::kMoveLeft, 20);
                  
                  break;
              }
              case 6: //display 6
              {
                  M5.dis.animation((uint8_t *)image_num6B, 150, LED_DisPlay::kMoveLeft, 20);
                  
                  break;
              }
              case 7: //display 7
              {
                  M5.dis.animation((uint8_t *)image_num7B, 150, LED_DisPlay::kMoveLeft, 20);
                
                  break;
              }
              case 8: //display 8
              {
                  M5.dis.animation((uint8_t *)image_num8B, 150, LED_DisPlay::kMoveLeft, 20);
                  
                  break;
              }
              case 9: //display 9
              {
                  M5.dis.animation((uint8_t *)image_num9B, 150, LED_DisPlay::kMoveLeft, 20);
                 
                  break;
              }
            }
            delayInterval(750);
            M5.update();
}

//displays the unit in the ones place
void displayOnes(int TempTens, int Temp, int &TempOnes)
{
  if(isCelsius == false)
  {
    Temp = Temp - 100;
  }
  
  TempOnes = Temp - (TempTens * 10);
      
            //display number in the ones place
            switch(TempOnes)
            {
              case 0: //display 0
              {
                  M5.dis.animation((uint8_t *)image_num0B, 150, LED_DisPlay::kMoveLeft, 20);
                  
                  break;
              }
      
              case 1: //display 1
              {
                  M5.dis.animation((uint8_t *)image_num1B, 150, LED_DisPlay::kMoveLeft, 20);
                 
                  break;
              }
              case 2: //display 2
              {
                  M5.dis.animation((uint8_t *)image_num2B, 150, LED_DisPlay::kMoveLeft, 20);
                 
                  break;
              }
              case 3: //display 3
              {
                  M5.dis.animation((uint8_t *)image_num3B, 150, LED_DisPlay::kMoveLeft, 20);
               
                  break;
              }
              case 4: //display 4
              {
                  M5.dis.animation((uint8_t *)image_num4B, 150, LED_DisPlay::kMoveLeft, 20);
                  
                  break;
              }
              case 5: //display 5
              {
                  M5.dis.animation((uint8_t *)image_num5B, 150, LED_DisPlay::kMoveLeft, 20);
                 
                  break;
              }
              case 6: //display 6
              {
                  M5.dis.animation((uint8_t *)image_num6B, 150, LED_DisPlay::kMoveLeft, 20);
                  
                  break;
              }
              case 7: //display 7
              {
                  M5.dis.animation((uint8_t *)image_num7B, 150, LED_DisPlay::kMoveLeft, 20);
                  
                  break;
              }
              case 8: //display 8
              {
                  M5.dis.animation((uint8_t *)image_num8B, 150, LED_DisPlay::kMoveLeft, 20);
                
                  break;
              }
              case 9: //display 9
              {
                  M5.dis.animation((uint8_t *)image_num9B, 150, LED_DisPlay::kMoveLeft, 20);
                  
                  break;
              }
            }
            delayInterval(850);
            M5.update();
}


void setup() {
  // put your setup code here, to run once:
    M5.begin(true, true, true);
    M5.IMU.Init();

    M5.IMU.getTempData(&currentTemp);
    Serial.print("The temperature is ");
    Serial.println(currentTemp);    // print the temperature value

    TempArray[tempCounts] = currentTemp;
    graphTemp[tempCounts] = currentTemp;
    SumofTemp += currentTemp;
    tempCounts++;
    counterArray++;
    averageTemp = SumofTemp / tempCounts;
    //Serial.print("The average temperature is ");
    //Serial.println(averageTemp);    // print the average temperature value
}

void loop() 
{

  readTemp();
  
  M5.IMU.getAttitude(&pitch, &roll);

  if(roll > -10 && roll < 0 && pitch > roll && pitch < 0) //face up
  {
    atomState = true;
  }

  if(M5.Btn.wasPressed()) //button pressed
  {
    atomState = true;
  }

  //print states of functions
  Serial.printf("%d,%i,%d\n", atomState, optionsCTR, modeState);
  delayInterval(500);

  while(atomState == true)
  {
      
      //get current pitch and roll
      M5.IMU.getAttitude(&pitch, &roll);

      if(modeState == false)
      {
          if(pitch < -10)
          {
            optionsCTR++;
            if (optionsCTR >= 5) //if counter exceeds number of states
            {
               optionsCTR = 0; //reset counter
            }
            delayInterval(500); //so that no other values are read
          }
        
          else if(pitch > 10)
          {
            optionsCTR--;
            if (optionsCTR <= -1) //if counter exceeds number of states
            {
               optionsCTR = 4; //reset counter
            }
            delayInterval(500); //so that no other values are read
          }
      }
     
      switch(optionsCTR)
      {
        case 0: //Show Active Temperature + Units
        {
          if(modeState == false)
          {
            M5.dis.displaybuff((uint8_t *)image_num1W, 0, 0);
            M5.update();
  
            if(M5.Btn.wasPressed())
            {
              modeState = true;
            } 
          }

          else if(modeState == true)
          {
            if(isCelsius == true)
            {
              Temp = currentTemp;
            }
            
            else if(isCelsius == false)
            {
              Temp = convertF(currentTemp);
            }
            
            //check if number is negative
            checkNegative(Temp);
            Temp=abs(Temp);

            //display the number in the tens place
            displayTens(TempTens, Temp);

            //display number in the ones place
            displayOnes(TempTens, Temp, TempOnes);

            //display the unit (fahrenheit)
            if(isCelsius == false)
            {
              M5.dis.animation((uint8_t *)image_degreeF, 150, LED_DisPlay::kMoveLeft, 20);
              delayInterval(700);
              M5.update();
            }
            
            //display the unit (celsius)
            else
            {
              M5.dis.animation((uint8_t *)image_degree, 150, LED_DisPlay::kMoveLeft, 20);
              delayInterval(700);
              M5.update();
            }
          }

          break;
          
        }
    
        case 1: //Show average of last 24 hours of temperature + Units
        {
          
          if(modeState == false)
          {
            M5.dis.displaybuff((uint8_t *)image_num2W, 0, 0);
            M5.update();

            if(M5.Btn.wasPressed())
            {
              modeState = true;
            } 
          }

          if(modeState == true)
          {

            if(isCelsius == true)
            {
              AveTemp = averageTemp;
            }
            
            else if(isCelsius == false)
            {
              AveTemp = convertF(averageTemp);
            }
            
            checkNegative(AveTemp);
            AveTemp = abs(AveTemp);

            //display the number in the tens place
            displayTens(TempTens, AveTemp);

            //display number in the ones place
            displayOnes(TempTens, AveTemp, TempOnes);
      
            //display the unit (fahrenheit)
            if(isCelsius == false)
            {
              M5.dis.animation((uint8_t *)image_degreeF, 150, LED_DisPlay::kMoveLeft, 20);
              delayInterval(700);
              M5.update();
            }
            
            //display the unit (celsius)
            else
            {
              M5.dis.animation((uint8_t *)image_degree, 150, LED_DisPlay::kMoveLeft, 20);
              delayInterval(700);
              M5.update();
            }
          
          }

          break;
           
        }

        case 2: //Show color scale of temperature range + current temperature as color
        {

          if(modeState == false)
          {
            M5.dis.displaybuff((uint8_t *)image_num3W, 0, 0);
            M5.update();
  
            if(M5.Btn.wasPressed())
            {
              modeState = true;
            }
          }

          if(modeState == true)
          
           { 
            M5.dis.displaybuff((uint8_t *)image_smallercolorscale, 0, 0);
            M5.update();
            delayInterval(500);
            
            if (currentTemp<0)//violet
            {
               for (int i=0;i<=9;i++)
               {
                  if (!leds[i])
                  {
                    M5.dis.drawpix(i, 0x30ff78);
                    
                  }
               } 
            }
           
            else if (currentTemp<10) //blue
            {
               for (int i=0;i<=9;i++)
                {
                  if (!leds[i])
                  {
                    M5.dis.drawpix(i, 0x2e41ff);
                    
                  }
                 }
            }
            else if (currentTemp<20) //green
               {
                for (int i=0;i<=9;i++)
                {
                    if (!leds[i])
                    {
                      M5.dis.drawpix(i, 0xff1e9a);
                      
                    }
                }
                }
                else if (currentTemp<30) //yellow
                {
                        for (int i=0;i<=9;i++)
                {
                    if (!leds[i])
                    {
                      M5.dis.drawpix(i, 0xfcff35);
                    }
                }
                }
                else //for the last red condition >30
                 {
                 for (int i=0;i<=9;i++)
                {
                    if (!leds[i])
                    {
                      M5.dis.drawpix(i, 0x008000);
                    }
                  }
                }
           }

           break;
           
        }

        case 3: //Show graph of temperature across a predefined range.
        {
          M5.dis.displaybuff((uint8_t *)image_num4W, 0, 0);
          M5.update();

          if(M5.Btn.wasPressed())
          {
            modeState = true;
          }
          
          if(modeState == true)
          { M5.dis.clear();
            for (int i=0;i<5; i++)
            
            //allocating height according to color if red all rows of a column get filled
            {Serial.println("graphtemp values is");
           
              if (currentTemp<0) 
              {
                graphTemp[i]=0;
              }
            else if (currentTemp<10) 
            {
              graphTemp[i]=1;
            }
            else if (currentTemp<20) 
            {
              graphTemp[i]=2;
            }
            else if (currentTemp<30) 
            {
              graphTemp[i]=3;
            }
            else if (currentTemp>30) 
            {
              graphTemp[i]=4;
            }
             Serial.println(graphTemp[i]);
            {for (int j=20;j<=24;j++)
            {for (int k=0;k<=graphTemp[i];k++)
            { 
              M5.dis.drawpix(j-(5*k), 0xff0000);//making a histogram plot
            }
              }
              }
          }
          }
           break;
        }

        case 4: //Change units
        {
          if(modeState == false)
          {
            M5.dis.displaybuff((uint8_t *)image_num5W, 0, 0);
            M5.update();

            if(M5.Btn.wasPressed())
            {
              modeState = true;
            }
          }

          if(modeState == true)
          {
              if(pitch < -10)
              {
                unitCTR++;
                if (unitCTR >= 2) //if counter exceeds number of states
                {
                   unitCTR = 0; //reset counter
                }
//                delayInterval(500); //so that no other values are read
              }
            
              else if(pitch > 10)
              {
                unitCTR--;
                if (unitCTR <= -1) //if counter exceeds number of states
                {
                   unitCTR = 1; //reset counter
                }
//                delayInterval(500); //so that no other values are read
              }

                Serial.printf("%d,%i,%d\n", isCelsius, unitCTR, modeState);
                delayInterval(500);
              
              switch(unitCTR)
              {
                case 0:
                {
                  //display the unit (celsius)
                  M5.dis.displaybuff((uint8_t *)image_degreeCW, 0, 0);
                  M5.update();

                  if(M5.Btn.wasPressed())
                  {
                    isCelsius = true;
                    modeState = false;
                    break;
                  }
                  break;
                }

                case 1:
                {
                  //display the unit (fahrenheit)
                  M5.dis.displaybuff((uint8_t *)image_degreeFW, 0, 0);
                  M5.update();

                  if(M5.Btn.wasPressed())
                  {
                    isCelsius = false;
                    modeState = false;
                    break;
                  }
                  break;
                }
              }
          }
           
        }
        
      }

    if(roll > 15 && roll > pitch) //face down
    {
      modeState = false;
      atomState = false;
      M5.dis.clear();
      M5.update();
      delayInterval(500);
  
    }

    break;
    
  }


//    M5.dis.clear();
//    M5.update();
//    delayInterval(500);
  

}
