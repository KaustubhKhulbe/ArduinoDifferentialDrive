#include "Arduino.h"
#include "Robot.h"
#include "Motor.h"
#include <math.h>
#include <EEPROM.h>

Robot::Robot(int motorA, int enA, int in1, int in2, int motorB, int enB,int  in3, int in4, float d_w, float w, float n){
  //Motor mA(motorA, enA, in1, in2);
  mA = new Motor(motorA, enA, in1, in2);
  mB = new Motor(motorB, enB, in3, in4);

  s = M_PI * d_w / n;
  alpha = s/w;
  c_a = cos(alpha);
  s_a = sin(alpha);
  theta = 0;
  u_x = cos(theta);
  //u_y = sin(theta);
  c = 0;
  address = 0;
  prevTime = millis();
  full = false;
}

void Robot::increment(boolean dir){
  c++;
  if(dir){
    mA -> increment();
    math(false);
  } else{
    mB -> increment();
    math(true);
  }

    if(millis() - prevTime > 300){
      Serial.println(p_x);
      Serial.println(p_y);
      //Serial.println(theta);
      prevTime = millis();
    }

//EEPROM CANNOT STORE NEGATIVE VALUES

//  if(!full && millis() - prevTime > 1000){
//    EEPROM.update(address, p_x);
//    address++;
//    EEPROM.update(address, p_y);
//    address++;
//    if (address == EEPROM.length()) {
//      address = 0;
//      full = true;
//    }
//    Serial.println(p_y);
//  }
}

void Robot::math(boolean negative){
  if(!negative) alpha = -alpha;
  u_x = cos(alpha) * u_x - sin(alpha) * u_y;
  u_y = sin(alpha) * u_x + cos(alpha) * u_y;

  p_x = p_x + (s/2) * u_x;
  p_y = p_y + (s/2) * u_y;

  if(!negative) alpha = -alpha;
  if(negative) theta -= alpha; else theta += alpha;

  u_x = cos(theta);
  u_y = sin(theta);
  
}

void Robot::moveForward(int steps, int mLeft, int mRight, boolean correct){
   // Set Motor A forward
   int currA = mA -> count;
   int currB = mB -> count;
   digitalWrite(mA -> in1, HIGH);
   digitalWrite(mA -> in2, LOW);
 
   // Set Motor B forward
   digitalWrite(mB -> in1, HIGH);
   digitalWrite(mB -> in2, LOW);
   
  while(mA -> count - currA < steps && mB -> count - currB < steps){
      analogWrite(mA -> en, min(mRight, 255));
      analogWrite(mB -> en, min(mLeft, 255));
//      Serial.println(mA -> count);
//      Serial.println(mB -> count);
    }
  analogWrite(mA -> en, 0);
  analogWrite(mB -> en, 0);

}
