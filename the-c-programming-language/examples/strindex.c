#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

static int _getline(char line[], int max);
static int strindex(char source[], char searchfor[]);

char pattern[] = "than"; /* pattern to search for */

/* find all lines matching pattern */
int main() {
  char line[MAXLINE];
  int found = 0;

  while (_getline(line, MAXLINE) > 0)
    if (strindex(line, pattern) >= 0) {
      printf("%s", line);
      found++;
    }
  return found;
}

/* _getline: get a line into s, return length */
static int _getline(char s[], int lim) {
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

/* strindex: return index of t in s, -1 if none */
static int strindex(char s[], char t[]) {
  int i, j, k;

  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
  }
  return -1;
}
