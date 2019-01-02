#include<stdio.h>
#include"stack.h"

int main(void){
  int i=0;
  while(i++<4){
    push(i);
  }
  i=0;
  while(i++<5){
    if(!isempty())
      printf("top element is %d\n", pop());
    else
      printf("stack is empty\n");
  }
}
