#include"stack.h"

int stack_array[MAX_SIZE];
int stack_pointer=-1;

void push(const int x){
  if(stack_pointer<MAX_SIZE){
    stack_array[++stack_pointer]=x;
  }
}

int pop(){
  return (stack_pointer>=0) ? stack_array[stack_pointer--] : -1;
}

int isempty(){
  return stack_pointer==-1;
}
