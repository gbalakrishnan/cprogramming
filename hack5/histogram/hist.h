#ifndef HIST_H
#define HIST_H

#define MAX_WORDS 1000
#define MAX_WORD_LEN 10

enum WRD_DETECT_FLAG {FALSE, TRUE};

/* 
  Init the state machine before use.
  This function must be called before
  the use of this library.
 */
void init(void);

/*
  Each character read from input can be
  passed to the state machine using this
  function.
  It will return the status i.e. if a word
  is detected or not by passing TRUE or FALSE.
 */
enum WRD_DETECT_FLAG addCtoW(int c);

/*
  When addCtoW() returns TRUE call this method
  to get the length of the word just parsed.
 */
int getWL(void);

/*
  Call this function with the word length 
  obtained to update the histogram word count
  for words of specific lengths.
 */
void incWrdCount(int wl);

/*
  Print the histogram horizontally.
 */
void printHist(void);
#endif
