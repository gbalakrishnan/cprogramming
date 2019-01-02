#include <stdio.h>
#include "hist.h"

static const int IN=1;
static const int OUT=0;
static int state = OUT;
static int wl=0;
static int hist_wc[MAX_WORD_LEN];

void init(void){
  int i;
  for(i=0;i<MAX_WORD_LEN;i++){
    hist_wc[i]=0;
  }
}

enum WRD_DETECT_FLAG addCtoW(int c){
  if(state == OUT){
    if(c != ' ' && c != '\n' && c != '\t'){
      wl=1;
      state = IN;
    }
  }
  else {
    if(c == ' ' || c == '\n' || c == '\t'){
      state = OUT;
    }
    else{
      wl++;
    }
  }
  return state==OUT && wl!=0 ? TRUE : FALSE;
}

int getWL(void){
  return wl;
}

void incWrdCount(int wl){
  hist_wc[wl-1]++;
}

void printHist(void){
  int i,j;
  for(i=0;i<MAX_WORD_LEN;i++){
    printf("%d - ",i+1);
    for(j=0;j<hist_wc[i];j++){
      printf("*");
    }
    printf("\n");
  }
}
