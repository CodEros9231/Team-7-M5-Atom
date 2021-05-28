

#include "M5Atom.h"
//#include "fastLED.h"
#include <pixeltypes.h>
//int LED_BUILTIN=13;

uint8_t DisBuff[2 + 5 * 5 * 3];

void setBuff(uint8_t Rdata, uint8_t Gdata, uint8_t Bdata) //sets hex color values for entire LED grid by R G B
{
    DisBuff[0] = 0x05;
    DisBuff[1] = 0x05;
    for (int i = 0; i < 25; i++)
    {
        DisBuff[2 + i * 3 + 0] = Rdata; //RED
        DisBuff[2 + i * 3 + 1] = Gdata; //GREEN
        DisBuff[2 + i * 3 + 2] = Bdata; //BLUE
    }
}


void setup() //default start state of Atom
{   Serial.begin(115200);
    M5.begin(true, false, true);
    delay(10);
    setBuff(0x00, 0x00, 0x00); //sets the light color at the beginning to off
    M5.dis.displaybuff(DisBuff);
    //pinMode(LED_BUILTIN, OUTPUT);
}

uint8_t FSM = 1; //set counter for button presses

void loop()
{
    if (M5.Btn.wasPressed()) //if button pressed
    {

        switch (FSM)
        {
        case 0: //LED off
            setBuff(0x00, 0x00, 0x00);
            
            break;
        
        case 1: //LED Red blinking 
        { M5.dis.fillpix(0x008000);//filling with red color
        delay(50);  //50 ms delay
          for(int i=1;i>0;i++)
          {
            M5.dis.fillpix(0x000000);//filling with no colors
          delay(1000);//black for 1 second
            M5.dis.fillpix(0x008000);//again fills with red
            delay(50);// 50 ms delay
          } 
          break;
        }  
        //need the lights to change after clicking the button  
        case 2: //LED White Blinking
            setBuff(0xff, 0xff, 0xff);
            break;
        case 3: //LED Red strobing
        {
            setBuff(0xff, 0x00, 0x00);
          
            break;
    
        }
        case 4: //LED White
            setBuff(0xff, 0xff, 0xff);
            break;
        default:
            break;
        }
        M5.dis.displaybuff(DisBuff);

        FSM++;
        if (FSM >= 5)
        {
            FSM = 0;
        }
    }

    delay(50);
    M5.update();
}
