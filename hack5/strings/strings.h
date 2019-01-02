#ifndef _STRINGS_H_
#define _STRINGS_H_
int strln(const char str[]);
void compress(const char str[], char compressed[]);
void reverse(const char str[], char reverse[]);
int nwords(const char str[]);
int nlines(const char str[]);
int nchars(const char str[]);
int nchar(const char str[], char a);
int issubstring(const char str[], const char sub[]);
#endif
