

#include "M5Atom.h"

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
{
    M5.begin(true, false, true);
    delay(10);
    setBuff(0x00, 0x00, 0x00); //sets the light color at the beginning to off
    M5.dis.displaybuff(DisBuff);
}

uint8_t FSM = 0; //set counter for button presses

void loop()
{
    if (M5.Btn.wasPressed()) //if button pressed
    {

        switch (FSM)
        {
        case 0: //LED off
            setBuff(0x00, 0x00, 0x00);
            break;
        case 1: //LED Red
            setBuff(0xff, 0x00, 0x00);
            break;
        case 2: //LED White
            setBuff(0xff, 0xff, 0xff);
            break;
        case 3: //LED Red
            setBuff(0xff, 0x00, 0x00);
            break;
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


/*
 while (FSM == 1)
            {
                setBuff(0xff, 0xff, 0xff);
                delay(1000);
                setBuff(0x00, 0x00, 0x00);
                delay(1000);
            }
 */
