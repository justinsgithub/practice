void real(char s, char t) {
  // Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into visible escape
  // sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as
  // well, converting escape sequences into the real characters.
}

void escape(char s, char t) {
  char st[] = "blah\tha	ha";
  // Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into visible escape
  // sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as
  // well, converting escape sequences into the real characters.
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
