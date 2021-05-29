#include "M5Atom.h"
bool IMU6886Flag = false;

void setup() {
  // put your setup code here, to run once:
M5.begin(true,false,true);
delay(20);
}

void loop() {
  M5.dis.drawpix(0,0,0xffffff);
  M5.update();
  // put your main code here, to run repeatedly:

}
