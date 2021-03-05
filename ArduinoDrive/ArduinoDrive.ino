#include "Robot.h"
#include <EEPROM.h>

Robot robot(3,10,9,8,2,5,7,6,2.7,5,20);
//int word_address = 0;
void setup(){
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt (robot.mA -> motor), incrementA, RISING);  // Increase counter A when speed sensor pin goes High
  attachInterrupt(digitalPinToInterrupt (robot.mB -> motor), incrementB, RISING);  // Increase counter B when speed sensor pin goes High
  robot.moveForward(100, 200, 0, false);
//  Serial.println(word_address);
//  for(int i = 0; i < word_address-1; i++){
//    float x = EEPROM.read(i);
//    float y = EEPROM.read(i+1);
//    Serial.print(x);
//    Serial.print(" ");
//    Serial.print(y);
//    Serial.println();
//  }
}

void loop(){
//  String str = String(robot.p_x) + ", " + String(robot.p_y);
//  if(word_address < EEPROM.length()){
//    EEPROM.write(word_address, robot.p_x);
//    EEPROM.write(word_address+1, robot.p_y);
//    word_address+=2;
//  }
  
}

void incrementA(){
  robot.increment(true);
  //Serial.println(robot.mA -> count);
}


void incrementB(){
  robot.increment(false);
  //Serial.println(robot.mB -> count);
}
