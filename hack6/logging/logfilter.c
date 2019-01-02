#include"logfilter.h"
#define IMPOSSIBLE_LARGE_DAY 32
#define IMPOSSIBLE_LARGE_MONTH 13
#define IMPOSSIBLE_LARGE_YEAR 10000

#define IMPOSSIBLE_SMALL_DAY 0
#define IMPOSSIBLE_SMALL_MONTH 0
#define IMPOSSIBLE_SMALL_YEAR 0

entry getFirst(const entry log[], const int len){
  int i;
  entry e={.logdate={.day=IMPOSSIBLE_LARGE_DAY,.month=IMPOSSIBLE_LARGE_MONTH,.year=IMPOSSIBLE_LARGE_YEAR}};

  for(i=0;i<len;i++){
    if(dtcompare(e.logdate,log[i].logdate)==1){
      e = log[i];
    }
  }
  return e;
}

entry getLast(const entry log[], const int len){
  int i;
  entry e={.logdate={.day=IMPOSSIBLE_SMALL_DAY,.month=IMPOSSIBLE_SMALL_MONTH,.year=IMPOSSIBLE_SMALL_YEAR}};

  for(i=0;i<len;i++){
    if(dtcompare(e.logdate,log[i].logdate)==-1){
      e = log[i];
    }
  }
  return e;
}

void sort(entry log[], const int len){
  int gap, i, j;
  entry temp;

  for(gap=len/2;gap>0;gap/=2)
    for(i=gap;i<len;i++)
      for(j=i-gap;j>=0 && dtcompare(log[j].logdate,log[j+gap].logdate)==1;j-=gap){
        temp = log[j];
        log[j] = log[j+gap];
        log[j+gap] = temp;
      }
}

static int bin_search(const entry e, entry log[], const int len){
  int low, high, mid;

  low=0;
  high=len-1;
  while(low<=high){
    mid=(low+high)/2;
    if(dtcompare(e.logdate, log[mid].logdate)==-1)
      high=mid-1;
    else if(dtcompare(e.logdate, log[mid].logdate)==1)
      low=mid+1;
    else
      return mid;
  }
  return -1;
}

static int linear_search(const entry e, entry log[], const int len){
  int i,r=-1;
  for(i=0;i<len;i++){
    if(dtcompare(log[i].logdate,e.logdate)==0){
      r=i;
      break;
    }
  }
  return r;
}

int search(const entry e, entry log[], const int len, enum SEARCH_TYPE type){
  int pos;

  switch(type){
    case LINEAR: pos=linear_search(e, log, len); break;
    case BINARY: pos=bin_search(e, log, len); break;
    default: pos=-1;break;
  }
  return pos;
}
