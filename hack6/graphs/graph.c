#include<math.h>
#include<stdio.h>
#include"graph.h"

#define BIT_CHUNK 8
#define BASE2 2

void store(byte* bmp, const int* adj_matrix, const int size){
  int i,j,p=BIT_CHUNK-1;

  // initialize the bitmap to 0
  for(i=0;i<size/BIT_CHUNK;i++)
    *(bmp+i)=0;

  for(i=0;i<size;i++){
    for(j=0;j<size;j++,p--){
      *bmp |= (byte)(pow(BASE2,p)*(*(adj_matrix+i*size+j)));
      if(p<=0){
        p=BIT_CHUNK;
        bmp++;
      }
    }
  }
}

void printbm(const byte* bmp, const int size){
  int i,j,p=BIT_CHUNK-1;

  for(i=0;i<size;i++){
    for(j=0;j<size;j++,p--){
      printf((*bmp&(byte)pow(BASE2,p))!=0 ? "1" : "0");
      if(p<=0){
        p=BIT_CHUNK;
        bmp++;
      }
    }
    printf("\n");
  }
}
