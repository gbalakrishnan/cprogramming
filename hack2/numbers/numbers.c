#include<math.h>
#include"numbers.h"

void peano_string(const short n, char rs[]){
  int i;
  for(i=0;i<n;i++)
    rs[i]='S';
  rs[i++]='0';
  rs[i]='\0';
}

int reverse(const int n){
  int r=0, t=n;
  while(t>0){
    r=r*10+t%10;
    t/=10;
  }
  return r;
}

void tobin(const short n, char bs[]){
  int t=n,i;
  int len=ceil(log2(t))+1;

  bs[len]='\0';
  for(i=0;i<len;i++)
    bs[i]='0';

  for(i=len-1;t>0;--i){
    bs[i]= t%2 ? '1' : '0';
    t/=2;
  }
}

int htod(char hex[]){
  return 0;
}

static int isprime(const int n){
    int i,r=1;
    for(i=2;i<n/2;i++){
      if(n%i==0){
        r=0;
        break;
      }
    }
    return r;
}

struct prime_pair goldbach(even_num n){
  struct prime_pair pp;
  int k;
  pp.p1=pp.p2=0;

  for(k=2;k<n/2;k++){
    if(isprime(k) && isprime(n-k)){
      pp.p1=k;
      pp.p2=n-k;
      break;
    }
  }
  return pp;
}
