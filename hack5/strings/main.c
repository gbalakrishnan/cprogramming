#include<stdio.h>
#include"strings.h"

int main(void){
  char str[]="Mississippi";
  char compressedStr[50], reversedStr[50];

  compress(str, compressedStr);
  printf("%s\n", compressedStr);

  reverse(str, reversedStr);
  printf("%s\n", reversedStr);

  printf("%d\n", issubstring(str, "pi"));
}
