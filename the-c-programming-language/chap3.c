#include <stdio.h>

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
