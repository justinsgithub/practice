#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);
int bufp = 0;      /* next free position in buf */
char buf[BUFSIZE]; /* buffer for ungetch */

/* getint: get next integer from input into *pn */
int getint(int *pn) {
  int c, sign;
  while (isspace(c = getch()))
    /* skip white space */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    /* it's not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

int getch(void) /* get a (possibly pushed back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
