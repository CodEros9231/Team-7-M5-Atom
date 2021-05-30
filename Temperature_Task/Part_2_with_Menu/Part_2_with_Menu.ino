


#include "M5Atom.h"

extern const unsigned char image_num1W[77];
extern const unsigned char image_num2W[77];
extern const unsigned char image_num3W[77];
extern const unsigned char image_num4W[77];
extern const unsigned char image_num5W[77];

bool IMU6886Flag = false;
bool atomState = false;
bool modeState = false;

int optionsCTR = 0;

double start, finished, elapsed;
double pitch, roll;

//double currentTime, lastUpdateTime, elapsed;
unsigned long currentTime=0;

void delayInterval(int num)
{ currentTime=millis();
 while (millis()<(currentTime+num))
 {
    //do nothing
 }
}

void setup() {
  // put your setup code here, to run once:
    M5.begin(true, true, true);
    M5.IMU.Init();
}

void loop() 
{
  // put your main code here, to run repeatedly:

  //put temperature function here

  //get current pitch and roll
  M5.IMU.getAttitude(&pitch, &roll);

  if(roll > -10 && roll < 0 && pitch > roll && pitch < 0) //face up
  {
    atomState = true;
  }

  if(M5.Btn.wasPressed()) //face up
  {
    atomState = true;
  }

  //print states of functions
  Serial.printf("%d,%i,%d\n", atomState, optionsCTR, modeState);
  delayInterval(500);

  while(atomState == true)
  {
      Serial.printf("%d,%i,%d,%.2f,%.2f\n", atomState, optionsCTR, modeState, pitch, roll);
      delayInterval(200);
      
      //get current pitch and roll
      M5.IMU.getAttitude(&pitch, &roll);
      
      if(pitch < -10)
      {
        optionsCTR++;
        if (optionsCTR >= 5) //if counter exceeds number of states
        {
           optionsCTR = 0; //reset counter
        }
        delay(500); //so that no other values are read
      }
    
      else if(pitch > 10)
      {
        optionsCTR--;
        if (optionsCTR <= -1) //if counter exceeds number of states
        {
           optionsCTR = 4; //reset counter
        }
        delay(500); //so that no other values are read
      }

      
      switch(optionsCTR)
      {
        case 0:
        {
          M5.dis.displaybuff((uint8_t *)image_num1W, 0, 0);
          M5.update();

          if(M5.Btn.wasPressed())
          {
            modeState = true;
          }

          if(modeState == true)
          {
            M5.dis.fillpix(0xFFFFFF);
            M5.update();
            delayInterval(500);

            M5.dis.clear();
            M5.update();
            delayInterval(500);
          }

          break;
          
        }
    
        case 1:
        {
          M5.dis.displaybuff((uint8_t *)image_num2W, 0, 0);
          M5.update();

          if(M5.Btn.wasPressed())
          {
            modeState = true;
          }

          if(modeState == true)
          {
            M5.dis.fillpix(0x0000FF);
            M5.update();
            delayInterval(500);

            M5.dis.clear();
            M5.update();
            delayInterval(500);
          }

          break;
           
        }

        case 2:
        {
          M5.dis.displaybuff((uint8_t *)image_num3W, 0, 0);
          M5.update();

          if(M5.Btn.wasPressed())
          {
            modeState = true;
          }

          if(modeState == true)
          {
            M5.dis.fillpix(0x008000);
            M5.update();
            delayInterval(500);

            M5.dis.clear();
            M5.update();
            delayInterval(500);
          }

          break;
           
        }

        case 3:
        {
          M5.dis.displaybuff((uint8_t *)image_num4W, 0, 0);
          M5.update();

          if(M5.Btn.wasPressed())
          {
            modeState = true;
          }

          if(modeState == true)
          {
            M5.dis.fillpix(0x008000);
            M5.update();
            delayInterval(500);

            M5.dis.clear();
            M5.update();
            delayInterval(500);
          }

          break;
           
        }

        case 4:
        {
          M5.dis.displaybuff((uint8_t *)image_num5W, 0, 0);
          M5.update();

          if(M5.Btn.wasPressed())
          {
            modeState = true;
          }

          if(modeState == true)
          {
            M5.dis.fillpix(0x008000);
            M5.update();
            delayInterval(500);

            M5.dis.clear();
            M5.update();
            delayInterval(500);
          }

          break;
           
        }
        
      }

    if(roll > 10 && roll > pitch) //face down
    {
      modeState = false;
      atomState = false;
    }
  }


    M5.dis.clear();
    M5.update();

  

}
