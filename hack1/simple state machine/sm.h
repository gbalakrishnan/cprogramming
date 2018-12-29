#ifndef _SM_H_
#define _SM_H_

enum switch_st{ON, OFF};
enum motor_st{IDLE, PUMPING};

void init(enum switch_st, enum motor_st);
void changeState(enum switch_st);
enum motor_st getMotorState(void);
enum switch_st getSwitchState(void);
#endif
