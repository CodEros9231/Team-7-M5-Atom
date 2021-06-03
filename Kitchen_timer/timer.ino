#include "M5Atom.h"
//int interval=1000,x_1=1;int y1=1,x2=0,y2=4,x3=4;
unsigned long previousMillis = millis(),currentMillis;

void setup() {
  // put your setup code here, to run once:
M5.begin(true, true, true);
M5.IMU.Init();
//------initial display of square lights------------
for (int x=0;x<5;x=x+4)
{
  for (int y=0;y<5;y++)
  {
      M5.dis.drawpix(x,y,0xff0000);
  } 
}
for (int y=0;y<5;y=y+4)
  {
  for (int x=0;x<5;x++)
  {
    M5.dis.drawpix(x,y,0xff0000);
    } 
  }
}

int interval=1000,x_1=1;int y_1=1,x2=0,y2=4,x3=4;
void loop() {//turning the leds on initially
  currentMillis=millis();

// here is where you'd put code that needs to be running all the time.

  




// put your main up  there, to run repeatedly:
  
  
  //M5.dis.drawpix(x_1,0,0x000000);
  
  if (x_1>-1)
  {
   if(currentMillis-previousMillis >=interval){
    M5.dis.drawpix(x_1,0,0x000000);
        previousMillis= currentMillis;
        (x_1)--;       
       }
  
  goto label;
    
  }
  
if (y_1<4)
{
 if(currentMillis-previousMillis >=interval)
 {
  M5.dis.drawpix(0,y_1,0x000000);
        previousMillis=currentMillis;
    (y_1)++; 
 }
 
 goto label;
}



  if(x2<4)
  {
    
  
    
     if(currentMillis-previousMillis >=interval){
      M5.dis.drawpix(x2,4,0x000000);
        previousMillis=currentMillis;
        x2++;
    }
 
 goto label;   
    }
  


if (y2>0)
{
 if(currentMillis-previousMillis>=interval){
    M5.dis.drawpix(4,y2,0x000000);
       previousMillis=currentMillis;
      y2--;   
    }
 
 goto label;
}

if (x3>=2)
{ 
 if(currentMillis-previousMillis >=interval){
  M5.dis.drawpix(x3,0,0x000000);
        previousMillis=currentMillis;
    x3--;
    }
  
  goto label;
  }
label:
;
}
