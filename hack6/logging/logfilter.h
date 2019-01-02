#ifndef _LOGFILTER_H_
#define _LOGFILTER_H_

#include"dates.h"
// two supported types of searches
enum SEARCH_TYPE{LINEAR, BINARY};
// two types of logins - user details available only if REG_USER
enum LOGIN_TYPE{REG_USER, GUEST};

typedef struct{
    char fname[20];
    char userid[50];
}user_details;

typedef struct{
  date logdate;
  enum LOGIN_TYPE type;

  // either there will be user details or else a text message
  // identify it based on LOGIN_TYPE
  union{
    char text[50];
    user_details ud;
  };
} entry;

// return the first entry based on date
entry getFirst(const entry log[], const int len);
// return the last entry based on date
entry getLast(const entry log[], const int len);
// mutates the given array of structures
// Use Shell Sort from textbook pp.62
void sort(entry log[], const int len);
// search for userid (linear search or binary search based on parameter)
int search(const entry e, entry log[], const int len, enum SEARCH_TYPE t);
#endif
