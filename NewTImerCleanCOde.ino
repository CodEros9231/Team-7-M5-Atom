unsigned long previousMillis=millis();
int patternarray[16]={1,0,5,10,15,20,21,22,23,24,19,14,9,4,3,2}
void setup() {
  // put your setup code here, to run once:
M5.begin(true, true, true);
M5.IMU.Init();
//Put the MenuThing() code here;
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
  if (secondTimer==true){goto down};
}
}

void loop() {
       if (newTime1==true)//newTime1 triggered whenever TotalTime1 received from other end
      {Timestamp1=millis();
       newTime1=false;
      }
      if (newTime2==true)
      {Timestamp2=millis();
      newTime2=false;
      }
      TimerLag=Timestamp2-Timestamp1;
      interval1=TotalTime1/15; interval2=TotalTime2/15;
      if (currentMillis1-previousMillis1>=interval1)
      {noOfpastIntervals1++;
        previousMillis1=currentMillis1;
        }
      if (currentMillis2-previousMillis2>=interval2)
      {noOfpastIntervals2++;
      previousMillis2=currentMillis2;
        }
      if (TimerNumber==1)
      {
      for (int i=0;i<noOfpastIntervals1;i++)
      {
        M5.dis.drawpix(patternarray[i],0xff0000);
        }
      }
      if (TimerNumber==2)
      {
           for (int i=0;i<noOfpastIntervals2;i++)
      {
        M5.dis.drawpix(patternarray[i],0xff0000);
        }
      }
        
      }
  // put your main code here, to run repeatedly:

}
