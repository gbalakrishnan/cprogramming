#include<stdio.h>
#include"numbers.h"

int main(void){

  char str[50];
  short n=1024,p=1023,t=100;
  peano_string(10,str);
  printf("%s\n",str);

  printf("%d is reversed as %d\n", n, reverse(n));
  tobin(p, str);
  printf("binary of %d is %s\n", p, str);

  struct prime_pair pp = goldbach(t);
  if(pp.p1==0 && pp.p2==0){
    printf("Goldbach's conjuncture if falsified.");
  }
  else{
    printf("Goldbach's conjuncture is true for %d with prime summands %d and %d\n",
            t, pp.p1, pp.p2);
  }
}
