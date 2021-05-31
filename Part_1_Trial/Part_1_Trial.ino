

#include "M5Atom.h"
#include "FastLED.h"


bool IMU6886Flag = false;

void setup() //default start state of Atom
{
    M5.begin(true, false, true);
    delay(50);
    if (!M5.IMU.Init()) IMU6886Flag = true; //sets flag to true

}

uint8_t FSM = 0; //set counter for button presses


void delayInterval(int num)
{ 
  currentTime=millis();
  while (millis()<(currentTime+num))
   {
      //do nothing
   }
}

void loop()
{
    if (M5.Btn.wasPressed()) //if button pressed
    {
      FSM++; //increment counter
        if (FSM >= 5) //if counter exceeds number of states
        {
            FSM = 0; //reset counter
        }
        M5.dis.clear(); //clear LEDs
            M5.update(); //update
            delay(50);
    }

     //Switch case for the current state of the LEDs
     switch (FSM)
        {
        case 0: //LED off
        {
            M5.dis.clear();
            M5.update();
            delay(200);
            break;
        }
        
        case 1: //LED Red Manual
        {
            //Turn all LEDs on to Red
            M5.dis.fillpix(0x008000);
            M5.update();
            delay(200); //interval of 200 ms

            //Turn all LEDs off
            M5.dis.clear();
            M5.update();
            delay(200); 

            //exit
            break;
        }
        
        case 2: //LED White
        {
            //Turn all LEDs on to White
            M5.dis.fillpix(0xFFFFFF);
            M5.update();
            delay(200); //interval of 200 ms

            //Turn all LEDs off
            M5.dis.clear();
            M5.update();
            delay(200);

            //exit loop
            break;
        }
        
        case 3: //LED Red Automatic
        {
            //!!Do normal blink behavior!!

            //Turn all LEDs on to Red
            M5.dis.fillpix(0x008000);
            M5.update();
            delay(200);

            //Turn all LEDs off
            M5.dis.clear();
            M5.update();
            delay(200);
            
            //determine acceleration values in x, y, z directions
            float accX = 0, accY = 0, accZ = 0;
            
            //get and store acceleration data
            if (IMU6886Flag == true) 
            {
                M5.IMU.getAccelData(&accX, &accY, &accZ);
            }

            //Keeps LED on when threshold reached on X axis
            if(accX >= 1 || accX <= -1)
            {
                M5.dis.fillpix(0x008000);
                M5.update();
                delay(1500);
            }

            //Keeps LED on when threshold reached on Z axis
            if(accZ >= 1 || accZ <= -1)
            {
                M5.dis.fillpix(0x008000);
                M5.update();
                delay(1500);
             }

            //exit loop
            break;
        }
        
        case 4: //LED White Automatic
        {
            //!!Do normal blink behavior!!

            //Turn all LEDs on to White
            M5.dis.fillpix(0xFFFFFF);
            M5.update();
            delay(200);

            //TUrn all LEDs off
            M5.dis.clear();
            M5.update();
            delay(200);
            
            //determine acceleration values in x, y, z directions
            float accX = 0, accY = 0, accZ = 0;
            if (IMU6886Flag == true) 
            {
                M5.IMU.getAccelData(&accX, &accY, &accZ);
            }

            //Keeps LED on when threshold reached in X axis
            if(accX >= 1 || accX <= -1)
            {
                M5.dis.fillpix(0xFFFFFF);
                M5.update();
                delay(1500);
            }

            //Keeps LED on when threshold reached in Z axis
            if(accZ >= 1 || accZ <= -1)
            {
                M5.dis.fillpix(0xFFFFFF);
                M5.update();
                delay(1500);
             }

            //exit loop
            break;
        }

        default: //default case
            break; //exit loop
        }
  
//  Serial.println(FSM); //prints counter of button presses
//  delay(500);

    delay(50);
    M5.update();
}
