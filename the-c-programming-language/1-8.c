#include <stdio.h>

int main() {
  int character, newlines, tabs, blanks;

  blanks = 0;
  tabs = 0;
  newlines = 0;
  while ((character = getchar()) != EOF) {
    if (character == ' ')
      ++blanks;
    if (character == '\t')
      ++tabs;
    if (character == '\n')
      ++newlines;
  }
  printf("blanks = %d\n", blanks);
  printf("tabs = %d\n", tabs);
  printf("newlines = %d\n", newlines);
}
