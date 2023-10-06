#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int character, num_lines, num_words, num_chars, state;

  state = OUT;
  num_lines = num_words = num_chars = 0;

  while ((character = getchar()) != EOF) {
    ++num_chars;
    putchar(character);
    if (character == '\n')
      ++num_lines;
    if (character == ' ' || character == '\n' || character == '\t') {
      state = OUT;
      putchar('\n');
    } else if (state == OUT) {
      state = IN;
      ++num_words;
    }
  }
  printf("%d %d %d\n", num_lines, num_words, num_chars);
}
