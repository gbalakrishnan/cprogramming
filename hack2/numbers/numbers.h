#ifndef _NUMBERS_H_
#define _NUMBERS_H_

typedef int even_num;
typedef int prime;

struct prime_pair{
  prime p1,p2;
};

void peano_string(const short n, char rs[]);
int reverse(const int n);
void tobin(const short n, char bs[]);
int htod(char hex[]);
struct prime_pair goldbach(even_num n);
#endif
