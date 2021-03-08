#include "Robot.h"
#include <EEPROM.h>

Robot robot(3,10,9,8,2,5,7,6,2.7,5,20);
int address = 0;
void setup(){
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt (robot.mA -> motor), incrementA, RISING);  // Increase counter A when speed sensor pin goes High
  attachInterrupt(digitalPinToInterrupt (robot.mB -> motor), incrementB, RISING);  // Increase counter B when speed sensor pin goes High
  robot.moveForward(50, 255, 190, false);
//  Serial.println(robot.p_x);
//  Serial.println(robot.p_y);
  robot.moveForward(200, 200, 0, true);
  robot.moveForward(200, 0, 255, true);
    robot.moveForward(200, 190, 255, true);
    robot.moveForward(800, 255, 180, true);
}

void loop(){
//  int value = EEPROM.read(address);
//  Serial.print("\t");
//  Serial.print(value, DEC);
//  Serial.print("\t");
//  value = EEPROM.read(address+1);
//  Serial.print(value, DEC);
//  Serial.println();
//
//    address = address + 2;
//  if (address == EEPROM.length()) {
//    address = 0;
//  }
  //delay(500);
}

void incrementA(){
  robot.increment(false);
  //Serial.println(robot.mA -> count);
}


void incrementB(){
  robot.increment(true);
  //Serial.println(robot.mB -> count);
}
