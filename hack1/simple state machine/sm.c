#include "sm.h"

static enum motor_st motor_state = IDLE;
static enum switch_st switch_state = OFF;

void init(enum switch_st ss, enum motor_st ms){
  switch_state = ss;
  motor_state = ms;
}

void changeState(enum switch_st ss){

  switch_state = ss;
  switch(switch_state){
    case ON:
      motor_state = PUMPING;
      break;
    case OFF:
      motor_state = IDLE;
      break;
  }
}

enum motor_st getMotorState(void){
  return motor_state;
}

enum switch_st getSwitchState(void){
  return switch_state;
}
