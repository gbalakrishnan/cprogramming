#include"matrix.h"

void diagonal(const int* arr, const int size, int dia[]){
   int i;
   for(i=0;i<size;i++){
     dia[i]=*(arr+i*(size+1));
   }
}

void upper(const int* arr, const int size, int* upper){
  int i,j;
  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      *(upper+i*size+j)=0;
    }
  }
  for(i=0;i<size;i++){
    for(j=i;j<size;j++){
      *(upper+i*size+j) = *(arr+i*size+j);
    }
  }
}

void lower(const int* arr, const int size, int* lower){
  int i,j;
  for(i=0;i<size;i++){
    for(j=0;j<size;j++){
      *(lower+i*size+j)=0;
    }
  }
  for(i=0;i<size;i++){
    for(j=0;j<i;j++){
      *(lower+i*size+j) = *(arr+i*size+j);
    }
  }
}

void row_exch(int* arr, const int size, int r1, int r2){
  int j, t;
  for(j=0;j<size;j++){
    t = *(arr+r1*size+j);
    *(arr+r1*size+j) = *(arr+r2*size+j);
    *(arr+r2*size+j) = t;
  }
}

void col_exch(int* arr, const int size, int c1, int c2){
  int i, t;
  for(i=0;i<size;i++){
    t = *(arr+i*size+c1);
    *(arr+i*size+c1) = *(arr+i*size+c2);
    *(arr+i*size+c2) = t;
  }
}
