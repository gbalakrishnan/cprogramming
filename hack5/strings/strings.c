#include<ctype.h>
#include"strings.h"


#define NUM_ALPHABETS 26

int strln(const char str[]){
  int c;
  for(c=0;str[c]!='\0';c++);
  return c;
}

void compress(const char str[], char compressed[]){
    int counter[NUM_ALPHABETS], i, j;

    for(i=0;i<NUM_ALPHABETS;counter[i++]=0);

    for(i=0;i<strln(str);i++){
      counter[tolower(str[i])-'a']++;
    }

    for(i=0,j=0;i<NUM_ALPHABETS;i++){
      if(counter[i]!=0){
        compressed[j++]='a'+i;
        compressed[j++]=counter[i]+'0';
      }
    }
    compressed[j]='\0';
}

void reverse(const char str[], char reverse[]){
  int len, i;
  for(i=0,len=strln(str);len>=0;len--,i++)
    reverse[i]=str[len-1];
  reverse[i]='\0';
}

int issubstring(const char str[], const char sub[]){
  int i, j, k,count;
  for(i=0,j=0;str[i]!='\0';i++){
    if(str[i]==sub[j]){
      for(k=i,count=0;sub[j]!='\0';j++,k++){
        if(str[k]==sub[j])
          count++;
        else
          break;
      }
      if(count==strln(sub))
        return i;
      else
        j=0;
    }
  }
  return -1;
}
