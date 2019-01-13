#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"logfilter.h"
/*
  Compilation command:
  gcc -g logcreator.c logfilter.o dates.o -o logcreator
 */
static entry getUD(){
  entry e;

  printf("Enter date (dd-mm-yy): ");
  scanf("%d-%d-%d",&e.logdate.day, &e.logdate.month, &e.logdate.year);

  printf("Enter login type (0 - REGISTERED USER, 1 - GUEST USER):");
  scanf("%d",&e.type);

  switch(e.type){
    case REG_USER:
                  printf("Enter first name:");
                  scanf("%s",e.ud.fname);
                  printf("Enter userid:");
                  scanf("%s",e.ud.userid);
                  break;
    case GUEST:
                  strcpy(e.text,"Guest user. User details not avialable.");
                  break;
  }
  return e;
}

int main(void){
  int choice;
  entry e;
  FILE* fptr;

  if ((fptr = fopen("log_trace.bin","wb")) == NULL){
       printf("Error! opening file");
       exit(1);
  }

  do{
    printf("User Details Menu\n");
    printf("1. Enter user details\n");
    printf("2. Exit\n");
    scanf("%d",&choice);
    //getchar();
    switch(choice){
      case 1:
            e=getUD();
            printf("Wrote %ld records\n", fwrite(&e, sizeof(entry), 1, fptr));
            break;
      case 2:
            break;
      default:
            printf("Wrong choice!\n");
            break;
    }
  }while(choice!=2);

  fclose(fptr);
  return 0;
}
