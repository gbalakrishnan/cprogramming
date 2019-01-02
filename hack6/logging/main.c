#include<stdio.h>
#include"logfilter.h"

int main(void){
  int i;
  entry log[]={
    {.logdate={.day=03,.month=01,.year=2019}, .ud={.fname="User 1",.userid="userid1"}},
    {.logdate={.day=02,.month=01,.year=2019}, .ud={.fname="User 2",.userid="userid2"}},
    {.logdate={.day=04,.month=01,.year=2019}, .ud={.fname="User 3",.userid="userid3"}},
    {.logdate={.day=01,.month=01,.year=2019}, .ud={.fname="User 4",.userid="userid4"}}
  };

  entry e = getFirst(log, 4);
  printf("First user: %s\n", e.ud.userid);

  e = getLast(log, 4);
  printf("Last user: %s\n", e.ud.userid);

  sort(log, 4);
  for(i=0;i<4;i++){
    printf("%s, ", log[i].ud.userid);
  }
  printf("\n");
  i=search(e, log, 4, BINARY);
  i!=-1 ? printf("%s\n",log[i].ud.fname) : printf("Entry not found");
}
