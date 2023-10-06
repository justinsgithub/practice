#include <stdio.h>

#define IN 1
#define OUT 0

// test by inputting different file types such as c files and markdown files,
// which contain all of the different special escape characters tabs, backspaces
// and other special characters are likely to uncover any bugs
int main() {
  int character, num_lines, num_words, num_chars, state;

  state = OUT;
  num_lines = num_words = num_chars = 0;

  while ((character = getchar()) != EOF) {
    ++num_chars;
    if (character == '\n')
      ++num_lines;
    if (character == ' ' || character == '\n' || character == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++num_words;
    }
  }
  printf("%d %d %d\n", num_lines, num_words, num_chars);
}
