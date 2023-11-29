#include "chapterone.h"
#include <stdio.h>

void tab_to_spaces(char line[], char detabbed_line[]) {
  int i, j, tabstop;
  i = 0;
  j = 0;
  tabstop = 1;

  while (line[i] != '\n') {
    if (line[i] == '\t') {
      // if j is less than 8, fill with spaces until next tabstop (not equal to 8 because array starts at 0, so 8 would
      // actually be 9 columns)
      while (j < (tabstop * TABSTOP)) {
        detabbed_line[j] = ' ';
        ++j;
      }
    } else {
      detabbed_line[j] = line[i];
      ++j;
    }

    // if j is at 8 (1 past first tabstop), we are now at the next tabstop (16, 24, ...)
    if (j == (tabstop * TABSTOP))
      ++tabstop;

    ++i;
  }

  detabbed_line[j] = '\n';
  detabbed_line[j + 1] = '\0';
}

int old_trim_line(char line[], int maxline) {
  int c, i;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    --i; // go to character before \n
    while (is_special_char(line[i])) {
      --i;
    }
    // assign end of line character after a non-whitespace character is found
    ++i;
    line[i] = c;
    ++i;
  }
  line[i] = '\0'; // signals end of char array
  return i;
}

/* reverse a character string */
void reverse(char to[], char from[], int len) {
  int i, j;

  i = 0;
  j = len - 2; // minus newline character and end of string character
  while (j >= 0) {
    to[i] = from[j];
    --j;
    ++i;
  }
  to[(len - 1)] = '\n';
  to[(len)] = '\0';
}

int trim_line(char line[], int line_len) {
  int i;
  // the character before \n
  i = line_len - 2;
  // check if character before \n is whitespace character, stop when get to first non-whitespace character
  while (is_special_char(line[i])) {
    --i;
  }
  // assign newline and end of string characters after first non-whitespace character
  line[i + 1] = '\n';
  line[i + 2] = '\0';
  // return new line_len
  return i + 2;
}

/* get_line: read characters until \n into line, return length */
int get_line(char line[], int maxline) {
  int c, i;
  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  // if i is 1, its a blankline (only contains a newline character \n)
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0'; // signals end of char array
  // if c is never '\n' then i will never be incremented and be 0, signaling end of file
  return i;
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while (((to[i] = from[i]) != '\0') && (i <= LONGLINE)) {
    ++i;
  }
}

int is_special_char(int c) {
  if (c != '\n' && c != '\t' && c != '\b' && c != ' ') {
    return 0;
  }
  return 1;
}
