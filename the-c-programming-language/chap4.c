#include <ctype.h>
#include <math.h>
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

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

static double _atofe(char s[]) {
  /* Exercise 4-2. Extend atof to handle scientific notation of the form 123.45e-6
   * where a floating-point number may be followed by e or E and an optionally signed exponent.
   * TODO: extract repeated loops into function
   */
  double val, power, exp;
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
  val = sign * val / power;
  if (tolower(s[i++]) == 'e') {
    sign = (s[i] == '-' ? -1 : 1);
    if (s[i] == '-')
      i++;
    for (exp = 0.0; isdigit(s[i]); i++) {
      exp = 10.0 * exp + (s[i] - '0');
    }
    exp = sign * exp;
    val = pow(val, exp);
  }
  return val;
}

/* test */
int atofe() {
  double sum, atof(char[]);
  char line[MAXLINE];
  char n1[] = "2.23e2";
  char n2[] = "2.23e-2";
  sum = 0;
  printf("%g\n", _atofe(n1));
  printf("%g\n", _atofe(n2));
  return 0;
}

/* Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add the modulus (%) operator
 * and provisions for negative numbers.
 */

/* Exercise 4-4. Add commands to print the top element of the stack without popping, to duplicate it, and to swap the
 * top two elements. Add a command to clear the stack.
 */

/* Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in Appendix B, Section 4.
 */

/* Exercise 4-6. Add commands for handling variables. (It's easy to provide twenty-six variables with single-letter
 * names.) Add a variable for the most recently printed value.
 */

/* Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input. Should ungets know about
 * buf and bufp, or should it just use ungetch?
 */

/* Exercise 4-8. Suppose that there will never be more than one character of pushback. Modify getch and ungetch
 * accordingly.
 */

/* Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what their properties ought to
 * be if an EOF is pushed back, then implement your design.
 */

/* Exercise 4-10. An alternate organization uses getline to read an entire input line; this make getch and ungetch
 * unnecessary. Revise the calculator to use this approach.
 */

/* Exercise 4-11. Modify getop so that it doesn't need to use ungetch. Hint: use an internal static variable.
 */

/* Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a
 * string by calling a recursive routine.
 */

/* Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the string s in place.
 */

/* Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t. (Block structure will help.)
 */

static int _strrindex(char s[], char t[]) {
  int i, j, k;
  int ri = -1; // right most index (-1 if not found)

  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0') {
      ri = i;
    }
  }
  return ri;
}

int strrindex() {
  /* Exercise 4-1. Write the function strrindex(s,t), which returns the position of the rightmost occurrence of t in s,
   * or -1 if there is none.
   */
  char line[MAXLINE];
  int found = 0;
  int i = -1;              // index pattern found starts at
  char pattern[] = "this"; /* pattern to search for */

  while (_getline(line, MAXLINE) > 0)
    if ((i = _strrindex(line, pattern)) >= 0) {
      printf("%s above match found at index %d\n\n", line, i);
      found++;
    }
  return found;
}
