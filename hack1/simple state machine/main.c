#include<stdio.h>
#include<ctype.h>
#include "sm.h"

#define TRUE 1

/**
  TODO: Change this implementation to read from a file the initial state and
  write the final state to a file. If the file is not present create one.
 */
int main(void){
  char c;
  init(OFF, IDLE);
  printf("Press Y for ON, N for OFF and X to quit\n");

  while(TRUE){
    c=tolower(getchar());
    getchar();
    if(c=='x')
      break;
    changeState(c=='y' ? ON : OFF);
  }

  printf("%s, %s\n", getSwitchState()==OFF ? "OFF" : "ON",
                    getMotorState()==IDLE ? "IDLE" : "PUMPING");
}
