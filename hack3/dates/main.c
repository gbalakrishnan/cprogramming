#include<stdio.h>
#include"dates.h"

int main(void){
  int leap_year_list[]={
    1804,1808,1812,1816,1820,1824,1828,1832,1836,1840,1844,1848,1852,1856,1860,1864,1868,1872,1876,1880,1884,1888,
    1952,1956,1960,1964,1968,1972,1976,1980,1984,1988,1992,1996,2000,2004,2008,2012,2016,2020,2024,2028,2032,2036,
    2040,2044,2048,2052,2056,2060,2064,2068,2072,2076,2080,2084,2088,2092,2096};
  int i;
  date d1={.day=22,.month=10,.year=2018}, d2={.day=22,.month=10,.year=2018};
  printf("%d\n",dtcompare(d1,d2));

  // test by running "./a.out | grep 0" and checking any 0s
  for(i=0;i<59;i++)
    printf("%d\n",isleap(leap_year_list[i]));
}
