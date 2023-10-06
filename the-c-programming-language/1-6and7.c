#include <stdio.h>

int main() {
  int c;

  c = getchar();
  while (c != EOF) {
    printf("%d", c != EOF); // 1 or 0
    printf("%d", EOF);      // EOF = -1
    c = getchar();
  }
}
