#include<stdio.h>
#include"matmul.h"

/*
    Compile command:
    gcc -g matmul.c main.c -D MULT2
                OR
    gcc -g matmul.c main.c -D MULT1
 */
int main(void){
  int i,j;
  int m1[3][3]={{1,2,3},
              {4,5,6},
              {7,8,9}},
      m2[3][3]={{1,1,1},
              {1,1,1},
              {1,1,1}},
      m3[3][3];
      /*
        TO TEST: Will this work if size of matrix is different from
                 MAX_COLS and MAX_ROWS?
      */
      #ifdef MULT1
      multiply1(m1,3,3,m2,3,3,m3);
      printf("MULT1: Passing arrays\n");
      for(i=0;i<3;i++){
        for(j=0;j<3;j++){
          printf("%3d", m3[i][j]);
        }
        printf("\n");
      }
      #endif

      #ifdef MULT2
      printf("MULT2: Passing pointers\n");
      multiply2((int*)m1,3,3,(int*)m2,3,3,(int*)m3);
      for(i=0;i<3;i++){
        for(j=0;j<3;j++){
          printf("%3d", m3[i][j]);
        }
        printf("\n");
      }
      #endif
}
