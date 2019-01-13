#include<stdio.h>
#include"matmul.h"

void multiply1(int m1[][MAX_COLS], int r1, int c1,
              int m2[][MAX_COLS], int r2, int c2,
              int m3[][MAX_COLS]){
  int i,j,k;
  for(i=0;i<r1;i++){
    for(j=0;j<c2;j++){
      m3[i][j]=0;
    }
  }

  for(i=0;i<r1;i++){
    for(j=0;j<c2;j++){
      for(k=0;k<r2;k++){
        m3[i][j]+=m1[i][k]*m2[k][j];
      }
    }
  }
}

void multiply2(int* m1, int r1, int c1,
               int* m2, int r2, int c2,
               int* m3){
  int i,j,k;
  for(i=0;i<r1;i++){
   for(j=0;j<c2;j++){
     *(m3+i*r1+j)=0;
   }
  }
  for(i=0;i<r1;i++){
    for(j=0;j<c2;j++){
      for(k=0;k<r2;k++){
        *(m3+i*r1+j)+=*(m1+i*r1+k) * *(m2+r2*k+j);
      }
    }
  }
}
