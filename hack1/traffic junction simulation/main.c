#include<stdio.h>
#include"tjsim.h"

int main(void){
  int max_iteration=50, max_nwv=5, max_wt=5;
  printf("max_iteration=%d max_nwv=%d max_wt=%d \n", max_iteration, max_nwv, max_wt);
  init_tjsim(max_iteration, 2, 3, 0, 1, OFF, max_nwv, max_wt);
  simulate();
}
