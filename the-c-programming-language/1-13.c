#include <stdio.h>
#define IN 1
#define OUT 0
#define LONGEST 30

/*
  write a program to print a histogram of the lengths of words in its input. It
  is easy to draw the histogram with the bars horizontal; a vertical orientation
  is more challenging.
 */
int main() {
  int character, current_word_length, state, index, bars;

  int word_lengths[LONGEST];

  state = OUT;
  current_word_length = 0;
  for (index = 0; index < LONGEST; ++index) {
    word_lengths[index] = 0;
  }
  while ((character = getchar()) != EOF) {
    if (state == IN) {
      ++current_word_length;
    }
    if (character == ' ' || character == '\n' || character == '\t') {
      ++word_lengths[current_word_length];
      current_word_length = 0;
      state = OUT;
    } else if (state == OUT) {
      state = IN;
    }
  }
  // horizontal orientation
  for (index = 1; index < LONGEST; ++index) {
    if (word_lengths[index] > 0) {
      printf("%d ", index);
      for (bars = 0; bars < word_lengths[index]; ++bars) {
        printf("|");
      }
      printf("\n");
    }
  }
  // vertical orientation
}

/* count digits, white space, others */
/*
int main() {
  int character, index, whitespace, others;
  int digits[10];

  whitespace = others = 0;
  for (index = 0; index < 10; ++index) {
    digits[index] = 0;
  }

  while ((character = getchar()) != EOF) {

    if (character >= '0' && character <= '9') {
      ++digits[character - '0'];
    } else if (character == ' ' || character == '\n' || character == '\t') {
      ++whitespace;
    } else {
      ++others;
    }
  }
  printf("digits =");
  for (index = 0; index < 10; ++index) {
    printf(" %d", digits[index]);
  }
  printf(", white space = %d, other = %d\n", whitespace, others);
}
*/
