#include<stdio.h>
#include"matrix.h"

#define SIZE 5
#define PRINT_MATRIX(a)   for(i=0;i<SIZE;i++){ \
                            for(j=0;j<SIZE;j++){ \
                              printf("%3d ", a[i][j]); \
                            } \
                            printf("\n");\
                          }
int main(void){
  int arr[SIZE][SIZE]={
    {10,0,1,2,55},
    {30,-1,4,5,6},
    {-3,10,33,0,1},
    {-4,50,4,0,10},
    {-6,-10,3,-90,1}}, new[SIZE][SIZE];
  int i, j, dia[SIZE];

  printf("\nOriginal\n");
  PRINT_MATRIX(arr)

  printf("\nDiagonal\n");
  diagonal((int*)&arr, SIZE, (int*)&dia);
  for(i=0;i<SIZE;i++){
    printf("%d ", dia[i]);
  }
  printf("\n");

  printf("\nUpper\n");
  upper((int*)&arr,SIZE,(int*)&new);
  PRINT_MATRIX(new)


  printf("\nLower\n");
  lower((int*)&arr,SIZE,(int*)&new);
  PRINT_MATRIX(new)

  printf("\nRow Exchange\n");
  row_exch((int*)&arr,SIZE,0,2);
  PRINT_MATRIX(arr)

  printf("\nColumn Exchange\n");
  col_exch((int*)&arr,SIZE,0,4);
  PRINT_MATRIX(arr)

}
