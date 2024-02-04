/* Example Declarations Start */
int *f();    /* f: function returning pointer to int */
int (*pf)(); /* pf: pointer to function returning int */
char **argv;
/* argv: pointer to pointer to char */
int (*daytab1)[13];
/* daytab1: pointer to array[13] of int */
int *daytab2[13];
/* daytab2: array[13] of pointer to int */
void *comp1();
/* comp1: function returning pointer to void */
void (*comp2)();
/* comp2: pointer to function returning void */
char (*(*x1())[])();
/* x1: function returning pointer to array[] of pointer to function returning char */
char (*(*x2[3])())[5];
/* x2: array[3] of pointer to function returning pointer to array[5] of char */
/* Example Declarations End */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define MAXTOKEN 100
enum { NAME, PARENS, BRACKETS };
void dcl(void);
void dirdcl(void);
int gettoken(void);
int tokentype;           /* type of last token */
char token[MAXTOKEN];    /* last token string */
char name[MAXTOKEN];     /* identifier name */
char datatype[MAXTOKEN]; /* data type = char, int, etc. */
char out[1000];          /* output string */

int dodcl() /* convert declaration to words */
{
  while (gettoken() != EOF) { /* 1st token on line */
    strcpy(datatype, token);  /* is the datatype */
    out[0] = '\0';
    dcl(); /* parse rest of line */
    if (tokentype != '\n')
      printf("syntax error\n");
    printf("%s: %s %s\n", name, out, datatype);
  }
  return 0;
}

int undcl() {
  int type;
  char temp[MAXTOKEN];
  while (gettoken() != EOF) {
    strcpy(out, token);
    while ((type = gettoken()) != '\n')
      if (type == PARENS || type == BRACKETS)
        strcat(out, token);
      else if (type == '*') {
        sprintf(temp, "(*%s)", out);
        strcpy(out, temp);
      } else if (type == NAME) {
        sprintf(temp, "%s %s", token, out);
        strcpy(out, temp);
      } else
        printf("invalid input at %s\n", token);
    printf("%s\n", out);
  }
  return 0;
}

int main() {
  dodcl();
  /*undcl();*/ /* comment out dcl and uncomment this one if you want to test */
  return 0;
}

int gettoken(void) /* return next token */
{
  int c, getch(void);
  void ungetch(int);
  char *p = token;
  while ((c = getch()) == ' ' || c == '\t')
    ;
  if (c == '(') {
    if ((c = getch()) == ')') {
      strcpy(token, "()");
      return tokentype = PARENS;
    } else {
      ungetch(c);
      return tokentype = '(';
    }
  } else if (c == '[') {
    for (*p++ = c; (*p++ = getch()) != ']';)
      ;
    *p = '\0';
    return tokentype = BRACKETS;
  } else if (isalpha(c)) {
    for (*p++ = c; isalnum(c = getch());)
      *p++ = c;
    *p = '\0';
    ungetch(c);
    return tokentype = NAME;
  } else
    return tokentype = c;
}

/* dirdcl: parse a direct declarator */
void dirdcl(void) {
  int type;
  if (tokentype == '(') { /* ( dcl ) */
    dcl();
    if (tokentype != ')')
      printf("error: missing )\n");
  } else if (tokentype == NAME) /* variable name */
    strcpy(name, token);
  else
    printf("error: expected name or (dcl)\n");
  while ((type = gettoken()) == PARENS || type == BRACKETS)
    if (type == PARENS)
      strcat(out, " function returning");
    else {
      strcat(out, " array");
      strcat(out, token);
      strcat(out, " of");
    }
}

/* dcl: parse a declarator */
void dcl(void) {
  int ns;
  for (ns = 0; gettoken() == '*';) /* count *'s */
    ns++;
  dirdcl();
  while (ns-- > 0)
    strcat(out, " pointer to");
}

#define BUFSIZE 100
int bufp = 0;      /* next free position in buf */
char buf[BUFSIZE]; /* buffer for ungetch */

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
