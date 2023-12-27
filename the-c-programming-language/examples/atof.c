#include <ctype.h>
#include <stdio.h>
#define MAXLINE 100

static int _getline(char line[], int max);

/* rudimentary calculator */
int main() {
  double sum, atof(char[]);
  char line[MAXLINE];

  sum = 0;
  while (_getline(line, MAXLINE) > 0)
    printf("\t%g\n", sum += atof(line));
  return 0;
}

/* atof: convert string s to double */
double atof(char s[]) {
  double val, power;
  int i, sign;

  for (i = 0; isspace(s[i]); i++) /* skip white space */
    ;

  sign = (s[i] == '-' ? -1 : 1);
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  return sign * val / power;
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
