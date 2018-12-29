#ifndef _MATRIX_H_
#define _MATRIX_H_

#define MAX_ROWS 50
#define MAX_COLS 50

// return the diagonal element in second argument
void diagonal(const int* arr, const int size, int dia[]);
// return upper triagle in the second argument
void upper(const int* arr, const int size, int* upper);
// return lower triagle in the second argument
void lower(const int* arr, const int size, int* lower);
// exchange the rows of a given matrix
void row_exch(int* arr, const int size, int r1, int r2);
// exchnage the columsn of a given matrix
void col_exch(int* arr, const int size, int c1, int c2);

#endif
