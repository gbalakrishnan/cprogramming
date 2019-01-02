#include<stdio.h>
#include<math.h>
#include"graph.h"

#define NUM_NODES MAX_NODES

int main(void){
  int adj_matrix[NUM_NODES][NUM_NODES]={
    {1,0,0,0,0,0,0,0,0,1},
    {0,1,0,0,0,1,0,0,0,0},
    {0,0,1,0,0,0,0,1,0,0},
    {0,0,0,1,0,0,0,0,1,0},
    {0,1,0,0,1,0,0,0,0,0},
    {0,1,1,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0},
    {1,0,0,0,0,0,0,1,0,0},
    {0,0,1,0,0,1,0,0,1,0},
    {1,1,1,1,1,1,1,1,1,1}
  };
  byte bm[MAX_BITMAP_SIZE];
  
  store((byte*)&bm, (int*)&adj_matrix, NUM_NODES);
  printbm((byte*)&bm, NUM_NODES);
}
