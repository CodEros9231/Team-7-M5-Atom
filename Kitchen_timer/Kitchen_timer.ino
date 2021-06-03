#include "M5Atom.h"

extern const unsigned char image_hour[77];
extern const unsigned char image_hourB[122];
extern const unsigned char image_secondB[122];
extern const unsigned char image_minute[77];
extern const unsigned char image_minuteB[122];
extern const unsigned char image_confirm[77];
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

bool IMU6886Flag = false;
bool atomState = false;
bool modeState = false;
int optionsCTR = 0;
int unitCTR = 0;

double start, finished, elapsed;
double pitch, roll;
unsigned long intervalTime = 0;
bool resetInterval = false;

bool timerSet1 = false;
bool timeSelect = false;

//FOR TIMER 1
int hourTimer1 = 0;
int minuteTimer1 = 0;
int secondTimer1 = 0;

bool hourloop = false;
bool minuteloop = false;
bool secondloop = false;


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

//displays the unit in the tens place
void displayTime(int timer)
{
          int Tens = 0;
          int Ones = 0;
          //determine number in the tens place
            Tens = (timer / 10) % 10;
            Ones = timer - (Tens * 10);


            //display number in the tens place
            switch(Tens)
            {
              case 0:
              {
                  //if less than 10, display nothing
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
            delayInterval(700);
            M5.update();

            switch(Ones)
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
            delayInterval(700);
            M5.update();
              
}

void countdown(int &seconds, int &minutes, int &hours)
{
  if(resetInterval == false)
  {
    intervalTime = 0;
    intervalTime = millis();
    resetInterval = true;
  }
  
  if(millis() >= intervalTime + 1000) //1 second timer
  {
    if(seconds > 0)
    {
      seconds--;
    }
    
    if(seconds == 0 && minutes > 0)
    {
      minutes--;
      seconds = 59;
    }
    else if(seconds == 0 && minutes == 0)
    {
      bool snoozeTimer = false;
      while(snoozeTimer == false)
      {
      M5.dis.fillpix(0xFFFFFF);
      delayInterval(500);
      M5.update();

      M5.dis.clear();
      delayInterval(500);
      M5.update();

      if(M5.Btn.wasPressed())
      {
        snoozeTimer = true;
      }
      }
    }
  }

//  if(minutes >= 1)
//  {
//    
//  }
}


void setup() {
  // put your setup code here, to run once:
    M5.begin(true, true, true);
    M5.IMU.Init();
}

void loop() 
{

  
  M5.IMU.getAttitude(&pitch, &roll); //Start recording pitch and roll values

  if(roll > -10 && roll < 0 && pitch > roll && pitch < 0) //if face up
  {
    atomState = true;
  }

  if(M5.Btn.wasPressed()) //button pressed
  {
    atomState = true;
  }

  //print states of functions
//  Serial.printf("%d,%i,%d\n", atomState, optionsCTR, modeState);
  delayInterval(300);

  while(atomState == true)
  {
      
      //get current pitch and roll
      M5.IMU.getAttitude(&pitch, &roll);
      double val = sqrt(pitch * pitch + roll * roll);

      if(modeState == false)
      {
          if(pitch < -10)
          {
            optionsCTR++;
            if (optionsCTR >= 3) //if counter exceeds number of states
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
               optionsCTR = 2; //reset counter
            }
            delayInterval(500); //so that no other values are read
          }
      }
     
      switch(optionsCTR)
      {
        case 0: //Timer 1
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

          if(modeState == true)
          {
            Serial.printf("%d\n", timerSet1);
            delayInterval(300);
            if(timerSet1 == false)
            {

              if(timeSelect == false)
              {

                if(pitch < -10)
                {
                  unitCTR++;
                  if (unitCTR >= 4) //if counter exceeds number of states
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
                     unitCTR = 3; //reset counter
                  }
  //                delayInterval(500); //so that no other values are read
                }
              }

              switch(unitCTR)
              {
                case 0: //hour
                {

                  if(hourloop == false)
                  {
                      M5.dis.displaybuff((uint8_t *)image_hour, 0, 0);
                      M5.update();

                      if(M5.Btn.wasPressed())
                      {
                        hourloop = true;
                      }
                  }

                  else if(hourloop == true)
                  {
                    timeSelect = true;
                      //get current pitch and roll
                      M5.IMU.getAttitude(&pitch, &roll); 
                        if(pitch < -10)
                        {
                          hourTimer1++;
                        }
                      
                        else if(pitch > 10)
                        {
                          if(hourTimer1 >= 0)
                          {
                            hourTimer1--;
                          }
                        }

                        displayTime(hourTimer1);
                        M5.dis.animation((uint8_t *)image_hourB, 150, LED_DisPlay::kMoveLeft, 12);
                        M5.update();
                        if(val >= 35 && val <= 50)
                        {
                          hourloop = false;
                          timeSelect = false;
                        } 
                    }
                    break;
                 }

                 case 1: //minute
                 {
                  if(minuteloop == false)
                  {
                      M5.dis.displaybuff((uint8_t *)image_minute, 0, 0);
                      M5.update();

                      if(M5.Btn.wasPressed())
                      {
                        minuteloop = true;
                      }
                  }

                  else if(minuteloop == true)
                  {
                      timeSelect = true;
                      //get current pitch and roll
                      M5.IMU.getAttitude(&pitch, &roll); 
                        if(pitch < -10)
                        {
                          minuteTimer1++;
                        }
                      
                        else if(pitch > 10)
                        {
                          if(hourTimer1 >= 0)
                          {
                            minuteTimer1--;
                          }
                        }

                        displayTime(minuteTimer1);
                        M5.dis.animation((uint8_t *)image_minuteB, 150, LED_DisPlay::kMoveLeft, 8);
                        M5.update();
                        if(val >= 35 && val <= 50)
                        {
                          minuteloop = false;
                          timeSelect = false;
                        } 
                    }
                    break;
                 }

                 case 2: //seconds
                 {
                  if(secondloop == false)
                  {
                      M5.dis.displaybuff((uint8_t *)image_num5W, 0, 0);
                      M5.update();

                      if(M5.Btn.wasPressed())
                      {
                        secondloop = true;
                      }
                  }

                  else if(secondloop == true)
                  {
                      timeSelect = true;
                      //get current pitch and roll
                      M5.IMU.getAttitude(&pitch, &roll); 
                        if(pitch < -10)
                        {
                         secondTimer1++;
                        }
                      
                        else if(pitch > 10)
                        {
                          if(secondTimer1 >= 0)
                          {
                            secondTimer1--;
                          }
                        }

                        displayTime(secondTimer1);
                        M5.dis.animation((uint8_t *)image_secondB, 150, LED_DisPlay::kMoveLeft, 12);
                        M5.update();
                        if(val >= 35 && val <= 50)
                        {
                          secondloop = false;
                          timeSelect = false;
                        } 
                    }
                    break;
                 }

                 case 3: //confirm
                 {
                      M5.dis.displaybuff((uint8_t *)image_confirm, 0, 0);
                      M5.update();

                      if(M5.Btn.wasPressed())
                      {
                        timerSet1 = true;
                        modeState = false;
                      }
                      break;
                  }
                }


                 
              }
             
              else if (timerSet1 == true)
              {
                countdown(secondTimer1, minuteTimer1, hourTimer1);
                
                if(hourTimer1 > 0)
                {
                displayTime(hourTimer1);
                M5.dis.animation((uint8_t *)image_hourB, 150, LED_DisPlay::kMoveLeft, 8);
                M5.update();
                }

                if(minuteTimer1 > 0)
                {
//                  int intervalTime2 = millis();
//                  
//                  if(millis() >= intervalTime2 + 5000) //1 second timer
//                  {             
                    displayTime(minuteTimer1);
                    M5.dis.animation((uint8_t *)image_minuteB, 150, LED_DisPlay::kMoveLeft, 20);
                    delayInterval(600);
                    M5.update();

                    displayTime(secondTimer1);
                    M5.dis.animation((uint8_t *)image_secondB, 150, LED_DisPlay::kMoveLeft, 8);
                    M5.update();

                    
//                  }
                }
                else
                {
//                  int intervalTime2 = millis();
//                  
//                  if(millis() >= intervalTime2 + 2000) //1 second timer
//                  {  
                  displayTime(secondTimer1);
                  M5.dis.animation((uint8_t *)image_secondB, 150, LED_DisPlay::kMoveLeft, 8);
                  M5.update();
//                  }
                }
              }

              
            
            
          }
          
        

          break;
          
        }
    
        case 1: //Timer 2
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
            
          }
           
        }

        case 2: //Reset
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
           }
           


           break;
           
        
        
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
