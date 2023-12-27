#include "helpers.h"
#include <ctype.h>
#include <float.h>
#include <limits.h>
#include <stdio.h>

/* lower: convert c to lower case; ASCII only */
int lower(int c) {
  // Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case, with a conditional
  // expression instead of if-else.
  /* OLD VERSION
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else
    return c;
  */

  /* NEW VERSION */
  (c >= 'A') && (c <= 'Z') && (c = c + 'a' - 'A');
  printf("%c", (char)c);
  return c;
}

// TODO: learn bitwise operations

/* bitcount: count 1 bits in x */
int bitcount(unsigned x) {
  // Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why. Use
  // this obsservation to write a faster version of bitcount.

  /* OLD VERSION
  int b;
  for (b = 0; x != 0; x >>= 1)
    if (x & 01)
      b++;
  return b;
  */
  /* NEW VERSION */
  return 0;
}
void setbits(int x, int p, int n, int y) {
  // Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the
  // rightmost n bits of y, leaving the other bits unchanged.
}

void invert(int x, int p, int n) {
  // Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted
  // (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
}

void rightrot(int x, int n) {
  // Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n bit
  // positions.
}

void squeeze(char fromthis[], const char deletethese[]) {
  // Exercise 2-4. Write an alternate version of squeeze (s1,s2) that deletes each character in s1 that matches any
  // character in the string s2.
  int i, j, k = 0;
  char temp[MAXLINE];
  // loop through each character in s1
  for (i = 0; fromthis[i] != '\0'; i++) {
    // check character in s1 against each character in s2
    for (j = 0; deletethese[j] != '\0'; j++) {
      // if a character matches, stop checking
      if (fromthis[i] == deletethese[j])
        break;
    }
    // if at end of array in s2, no characters matched and we can add character to new string
    if (deletethese[j] == '\0')
      temp[k++] = fromthis[i];
  }
  // this whole squeeze function could probably be much more efficient
  copy(fromthis, temp);
  printf("%s", fromthis);
}

int any(char inthis[], const char findthis[]) {
  // Exercise 2-5. Write the function any(s1,s2), which returns the first location in the string s1 where any character
  // from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library function strpbrk does
  // the same job but returns a pointer to the location.)
  int i, j;
  // loop through each character in s1
  for (i = 0; inthis[i] != '\0'; i++) {
    // check character in s1 against each character in s2
    for (j = 0; findthis[j] != '\0'; j++) {
      // if a character matches, stop checking and return location
      if (inthis[i] == findthis[j]) {
        printf("%d", i);
        return i;
      }
    }
  }
  // if made it through loop, no character was found, return -1
  i = -1;
  printf("%d", i);
  return i;
}

int chartohex(char c) {
  int diff, charval;
  // if it is not a letter, just subtract value of '0' to get decimal value
  if (isdigit(c))
    return (int)c - '0';
  // difference between character value and hex value
  diff = 'a' - 10;
  // lowercase letter so diff is accurate
  charval = tolower(c);
  // a - f = 10 - 15
  return charval - diff;
}

int hextoint(const char hexstring[]) {
  // Exercise 2-3. Write the function htoi(s), which converts a string of hexadecimal digits (including an optional 0x
  // or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
  int i, base, result;
  base = 16;
  result = 0;
  if (tolower(hexstring[1]) == 'x')
    i = 2;
  for (i = i; hexstring[i] != '\0'; ++i)
    result = base * result + chartohex(hexstring[i]);
  printf("result: %d", result);
  return 0;
}

int _no_logic_ops(char line[]) {
  // for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
  //   line[i] = c;
  // }
  // Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.

  // modification of getline() from earlier exercise
  int c, i;
  for (i = 0; i < MAXLINE - 1; ++i) {
    if ((c = getchar()) == EOF)
      break;
    if (c == '\n')
      break;
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

void no_logic_ops() {
  // To test _no_logic_ops
  int len;            /* current line length */
  char line[MAXLINE]; /* current input line */

  while ((len = _no_logic_ops(line)) > 0)
    if (len >= PRINTSIZE) {
      printf("%s", line);
    }
}

void type_ranges() {
  // Exercise 2-1. Write a program to determine the ranges of char, short, int, and long variables, both signed and
  // unsigned, by printing appropriate values from standard headers and by direct computation. Harder if you compute
  // them: determine the ranges of the various floating-point types.
  // TODO: finish

  printf("CHAR_MIN - CHAR_MAX = %d - %d\n", CHAR_MIN, CHAR_MAX);
  printf("CHAR_BIT = %d\n", CHAR_BIT);
  printf("\n");

  printf("SCHAR_MIN - SCHAR_MAX = %d - %d\n", SCHAR_MIN, SCHAR_MAX);
  printf("UCHAR_MAX = %d\n", UCHAR_MAX);
  printf("\n");

  printf("SHRT_MIN - SHRT_MAX = %d - %d\n", SHRT_MIN, SHRT_MAX);
  printf("USHRT_MAX = %d\n", USHRT_MAX);
  printf("\n");

  printf("INT_MIN - INT_MAX = %d - %d\n", INT_MIN, INT_MAX);
  printf("UINT_MAX = %d\n", UINT_MAX);
  printf("\n");

  printf("LONG_MIN - LONG_MAX = %ld - %ld\n", LONG_MIN, LONG_MAX);
  printf("ULONG_MAX = %ld\n", ULONG_MAX);
  printf("\n");

  printf("FLT_MIN %f\n", FLT_MIN);
  printf("FLT_MAX %f\n", FLT_MAX);
  printf("FLT_EPSILON %f\n", FLT_EPSILON);
  printf("\n");

  printf("DBL_MIN %f\n", DBL_MIN);
  printf("DBL_MAX %f\n", DBL_MAX);
  printf("DBL_EPSILON %f\n", DBL_EPSILON);
  printf("\n");

  printf("LDBL_MIN %Lf\n", LDBL_MIN);
  printf("LDBL_MAX %Lf\n", LDBL_MAX);
  printf("LDBL_EPSILON %Lf\n", LDBL_EPSILON);
  printf("\n");
}
