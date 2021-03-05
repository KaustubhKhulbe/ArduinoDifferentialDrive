#ifndef Motor_h
#define Motor_h

#include "Arduino.h"
class Motor
{
  public:
    Motor(int m_in, int en_in, int in1_in, int in2_in);
    void increment();
    int motor;
    int en;
    int in1;
    int in2;
    int count;
  private:
};

#endif
