#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int m_in, int en_in, int in1_in, int in2_in){
  motor = m_in;
  en = en_in;
  in1 = in1_in;
  in2 = in2_in;
  count = 0;
}

void Motor::increment(){
  count++;
}
