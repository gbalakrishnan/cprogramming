#include<stdio.h>
#include"queue.h"

int main(void){
  int i=0;
  while(i++<4){
    qadd(i);
  }
  i=0;
  while(i++<5){
    if(!isqempty()){
      printf("%d\n", qremove());
    }
    else{
      printf("Queue is empty!\n");
    }
  }
}
