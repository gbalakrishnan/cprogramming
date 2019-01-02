#include"queue.h"
int queue_array[MAX_QUEUE_SIZE];
int queue_start=0;
int queue_end=-1;

// TODO: What should happen when queue_end > MAX_QUEUE_SIZE but queue_start>0
// i.e. some elements are removed and so there is free space available?
void qadd(const int x){
  if(queue_end<MAX_QUEUE_SIZE)
    queue_array[++queue_end]=x;
}

int qremove(){
  return queue_start<=queue_end ? queue_array[queue_start++] : -1;
}

int isqempty(){
  return queue_start>queue_end;
}
