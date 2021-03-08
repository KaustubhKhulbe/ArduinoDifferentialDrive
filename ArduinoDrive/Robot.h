#ifndef Robot_h
#define Robot_h
#include "Arduino.h"
#include "Motor.h"
class Robot
{
  public:
    Robot(int motorA, int enA, int in1, int in2, int motorB, int enB,int  in3, int in4, float d_w, float w, float n);
    Motor* mA;
    Motor* mB;
    void increment(boolean dir);

    float s, theta, alpha;
    float u_x, u_y;
    float p_x, p_y;
    float c_a, s_a;
    int c;
    int address, prevTime;
    boolean full;

    void moveForward(int steps, int mLeft, int mRight, boolean correct);
    
    
  private:
    void math(boolean negative);
    //void rightMath();
};

#endif
