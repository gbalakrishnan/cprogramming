#ifndef _GRAPH_H_
#define _GRAPH_H_

#define MAX_NODES 10
#define MAX_BITMAP_SIZE 13

typedef char byte;

void store(byte* bmp, const int* adj_matrix, const int size);
void printbm(const byte* bmp, const int size);
#endif
