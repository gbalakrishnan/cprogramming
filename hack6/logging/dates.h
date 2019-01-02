#ifndef _DATES_H_
#define _DATES_H_

typedef struct{
  int day,
      month,
      year;
}date;
typedef int year;

int dtcompare(date d1, date d2);
int isleap(year y);
#endif
