#include <stdio.h>

/* TODO:
 * Exercise 3-4. In a two's complement number representation, our version of itoa does not handle the largest number
 * negative number, that is, the value of n equal to -(2wordsize-1). Explain why not. Modify it to print that value
 * correctly, regardless of the machine on which it runs.
 *
 * TODO:
 * Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b character representation in
 * the string s. In particular, itob(n,s,16) formats n as a hexadecimal integer in s.
 *
 * TODO:
 * Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum
 * field width; the converted number must be padded with blanks on the left if necessary to make it wide enough.
 *
 */

// TODO:
void expand(char s1[] /* a-z */, char s2[] /* expanded notation */) {
  // Exercise 3-2. Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the
  // equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle
  // cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.
  int i, j;
  char c1;
  i = j = 0;
  if (s1[i] == '-') { // leading - is taken literally
    s2[j++] = s1[i++];
  }
  for (int i = i; s1[i] != '\0'; i++) {
  }

  s2[j] = '\0';
  printf("%s\n", s2);
}

void expandtest() {
  char to[1000];
  int i = -100;
  i = -i;
  printf("%d", i);
  // expand("a-z", to);
  // expand("-a-z-", to);
}

void real(char to[], char from[]) {
  // Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into visible escape
  // sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as
  // well, converting escape sequences into the real characters.
  int c, i, n, j;
  j = i = n = 0;

  // TODO: pretty sure could be cleaner, too tired to think how right now
  while (from[i] != '\0') {
    c = from[i++];   // c is current char in array
    n = from[i];     // n is the next char in array, (since i was incremented above)
    if (c == '\\') { // check for escape character
      switch (n) {
      case 't':
        to[j++] = '\t'; // if 't' set to tab character
        i++;            // need to increment because don't want to use 't' in next loop
        break;
      case 'n':
        to[j++] = '\n'; // if 'n' set to new line character
        i++;            // see above
        break;
      default:
        break;
      }
    } else {
      to[j++] = c;
    }
  }
  to[j] = 0; // program prints extra characters without this? old memory location? Function below does not have same
             // behavior

  printf("%s\n\n", from);
  printf("%s", to);
}

void escape(char to[], char from[]) {
  // Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into visible escape
  // sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as
  // well, converting escape sequences into the real characters.
  int c, i = 0;
  int j = 0;

  while (from[i] != '\0') {
    c = from[i++];
    switch (c) {
    case '\t':
      to[j++] = '\\';
      to[j++] = 't';
      break;
    case '\n':
      to[j++] = '\\';
      to[j++] = 'n';
      break;
    default:
      to[j++] = c;
      break;
    }
  }
  to[j] = '\0'; // Program works fine without this.
  printf("%s\n\n", from);
  printf("%s", to);
}

/* _binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int _binsearch(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else // found match
      return mid;
  }
  return -1;
}

int binsearch(int x /* number to search */, int v[], int n /* length of array */) {
  // Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests
  // outside). Write a version with only one test inside the loop and measure the difference in run-time.
  // TODO: I dunno
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else // found match
      return mid;
  }
  return -1;
}
