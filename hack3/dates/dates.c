#include"dates.h"

int dtcompare(date d1, date d2){
  int r=-1;

  if(d1.year == d2.year && d1.month == d2.month && d1.day == d2.day){
    r=0;
  }
  else if((d1.year > d2.year) ||
          (d1.year == d2.year && d1.month > d2.month)||
          (d1.year == d2.year && d1.month == d2.month && d1.day > d2.day)){
    r=1;
  }

  return r;
}

int isleap(year y){
  return ((y%4==0 && y%100!=0) || y%400==0);
}
