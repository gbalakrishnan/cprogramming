#include<stdio.h>
#include<stdlib.h>
#include"logfilter.h"

#define MAX_ENTRIES 4

/*
  Compilation command:
   gcc -g logfilter.o dates.o main.c -o logreader -D USE_FILE
 */
int main(void){
  int i;

#ifndef USE_FILE
  entry log[10]={
    {.logdate={.day=03,.month=01,.year=2019}, .ud={.fname="User 1",.userid="userid1"}},
    {.logdate={.day=02,.month=01,.year=2019}, .ud={.fname="User 2",.userid="userid2"}},
    {.logdate={.day=04,.month=01,.year=2019}, .ud={.fname="User 3",.userid="userid3"}},
    {.logdate={.day=01,.month=01,.year=2019}, .ud={.fname="User 4",.userid="userid4"}}
  };
#else
  entry log[MAX_ENTRIES];
  FILE* fptr;

  if ((fptr = fopen("log_trace.bin","rb")) == NULL){
       printf("Error! opening file");
       exit(1);
  }
  fseek(fptr, 0L, SEEK_END);
  int sz = ftell(fptr);
  rewind(fptr);
  for(i=0;i<sz/sizeof(entry)-1;++i)
  {
    fread(&log[i], sizeof(entry), 1, fptr);
    printf("Read entry on %d-%d-%d\n",log[i].logdate.day, log[i].logdate.month,log[i].logdate.year);
  }
  fclose(fptr);
#endif

  entry e = getFirst(log, MAX_ENTRIES);
  e.type==REG_USER ? printf("First user: %s\n", e.ud.userid) :
                      printf("Guest user %d-%d-%d",e.logdate.day,e.logdate.month,e.logdate.year);


  e = getLast(log, MAX_ENTRIES);
  e.type==REG_USER ? printf("Last user: %s\n", e.ud.userid) :
                      printf("Guest user %d-%d-%d",e.logdate.day,e.logdate.month,e.logdate.year);

  sort(log, MAX_ENTRIES);
  for(i=0;i<4;i++){
    log[i].type==REG_USER ? printf("%s, ", log[i].ud.userid) :
                        printf("Guest user %d-%d-%d",e.logdate.day,e.logdate.month,e.logdate.year);
  }
  printf("\n");
  printf("Searching for %s\n",e.ud.fname);
  i=search(e, log, MAX_ENTRIES, BINARY);
  i!=-1 ? printf("Found %s\n",log[i].ud.fname) : printf("Entry not found");
}
