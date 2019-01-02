#include<stdio.h>
#include "hist.h"

int main(void){
  int c, wc=0, wl=0;

  init();
  while((c=getchar())!=EOF){
    if(c!='.' && c!=':' && c!=';'){
      if (addCtoW(c) == TRUE){
      	wc++;
      	wl=getWL();
      	incWrdCount(wl);
      }
    }
  }
  printf("# Histogram #\n");
  printHist();
}
