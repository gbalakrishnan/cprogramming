#include<stdio.h>
#include<stdlib.h>
#include"tjsim.h"

// increases by 1 and all updations happen between increments
static int sim_clk, max_iteration;
// max number of waiting vehicles and max waiting time
static int max_nwv, max_wt;
// increment randomly when light OFF or ON and decrement when light is ON
static int wenv, snnv;
// waiting time for xy bound cars
static int wewt, snwt;
// switch ON when wait time exceeds T or number of waiting vehicles increases N
static enum traffic_light snlight, welight;



// add or/and remove cars as per need
static void update_westate(void){
  // this can be tweaked to increase or decrease rate
  wenv += (rand()<(0.5*RAND_MAX)) ? 1 : 0;
  welight==ON ? wenv-- : wewt++;
}
static void update_snstate(void){
  snnv += (rand()<(0.5*RAND_MAX)) ? 1 : 0;
  snlight==ON ? snnv-- : snwt++;
}

// perform a switching in traffic light based on given condition
static void switching(void){
  if(snlight==ON && (wenv>=max_nwv || wewt>=max_wt)){
    printf("switching\n");
    welight = ON; snlight = OFF;
    wewt=0;
  }
  else if(welight==ON && (snnv>=max_nwv || snwt>=max_wt)){
    printf("switching\n");
    snlight = ON; welight = OFF;
    snwt=0;
  }
}

// increament the clock
static void inc_clk(void){
  sim_clk++;
}

// print the state information for previous iteration
static void print_state(void){
   printf("sim_clk=%d snlight=%d snnv=%d snwt=%d welight=%d wenv=%d wewt=%d\n",
          sim_clk,
          snlight, snnv, snwt,
          welight, wenv, wewt);
}


void init_tjsim(const int maxiter,
                const int iwenv, const int isnnv,
                const int iwewt, const int isnwt,
                enum traffic_light isnlight,
                const int mnwv,
                const int mwt){
   max_iteration = maxiter;
   sim_clk = 0;
   wenv = iwenv;
   snnv = isnnv;
   wewt = iwewt;
   snwt = isnwt;
   welight = (snlight = isnlight)==ON ? OFF : ON;
   max_nwv = mnwv;
   max_wt = mwt;
}

void simulate(void){
   while(sim_clk<max_iteration){
     update_westate();
     update_snstate();
     switching();
     inc_clk();
     print_state();
   }
}
