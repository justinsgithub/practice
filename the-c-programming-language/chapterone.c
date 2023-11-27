#include "chapterone.h"
#include <stdio.h>

// Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to
// achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to
// reach a tab stop, which should be given preference? Tab should be given preference or you would just use all blanks
// instead of any tabs otherwise.

// Exercise 1-22. Write a program to "fold" long input lines into two or more shorter lines after the last non-blank
// character that occurs before the n-th column of input. Make sure your program does something intelligent with very
// long lines, and if there are no blanks or tabs before the specified column.

// Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to handle quoted strings and
// character constants properly. C comments do not nest.

// Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses,
// brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This program
// is hard if you do it in full generality.)

void detab(unsigned short tabstop) {
  // Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number of blanks to space to
  // the next tab stop. Assume a fixed set of tab stops, say every "n" columns. Should "n" be a variable or a symbolic
  // parameter? Variable so that user can specify tabstop length.
  // TEST: to test the output should have no tabs but the lines should all be the same length as the input.

  int len;                /* current line length */
  char line[MAXLINE];     /* current input line */
  char reversed[MAXLINE]; /* reversed string saved here */

  while ((len = get_line(line, MAXLINE)) > 0) {
    printf("%s", line);
  }
}

/* reverse a character string */
void reverse(char to[], char from[], int len) {
  int i, j;

  i = 0;
  j = len - 2; // minus newline character and end of string character
  while (j >= 0) {
    to[i] = from[j];
    --j;
    ++i;
  }
  to[(len - 1)] = '\n';
  to[(len)] = '\0';
}

void reverse_input_lines() {
  // Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to write a program that
  // reverses its input a line at a time.
  int len;                /* current line length */
  char line[MAXLINE];     /* current input line */
  char reversed[MAXLINE]; /* reversed string saved here */

  while ((len = get_line(line, MAXLINE)) > 0) {
    reverse(reversed, line, len);

    printf("%s", reversed);
  }
}

int get_trimmed_line(char line[], int maxline) {
  int c, i, blankline;
  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    if (i == 0)
      blankline = BLANKLINE;
    if (is_special_char(c) == 0)
      blankline = 0;
    line[i] = c;
  }
  if (blankline == BLANKLINE)
    return BLANKLINE;
  if (c == '\n') {
    if (i == 0) {
      return BLANKLINE;
    }

    --i; // go to character before \n
    while (is_special_char(line[i])) {
      --i;
    }
    // assign end of line character after a non-whitespace character is found
    ++i;
    line[i] = c;
    ++i;
  }
  line[i] = '\0'; // signals end of char array
  return i;
}

void trim_line() {
  // Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely
  // blank lines.
  int len;            /* current line length */
  char line[MAXLINE]; /* current input line */

  while ((len = get_trimmed_line(line, MAXLINE)) > 0) {
    if (len != BLANKLINE)
      printf("%s", line);
  }
}

int is_special_char(int c) {
  if (c != '\n' && c != '\t' && c != '\b' && c != ' ') {
    return 0;
  }
  return 1;
}

void longer_than_80() {
  // Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.
  int len;            /* current line length */
  char line[MAXLINE]; /* current input line */

  while ((len = get_trimmed_line(line, MAXLINE)) > 0)
    if (len >= PRINTSIZE) {
      printf("%s", line);
    }
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[]) {
  int i;

  i = 0;
  while (((to[i] = from[i]) != '\0') && (i <= LONGLINE)) {
    ++i;
  }
}

/* get_line: read characters until \n into line, return length */
int get_line(char line[], int maxline) {
  int c, i;
  for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0'; // signals end of char array
  return i;
}

void print_long_lines() {
  // Exercise 1-16. Revise the main routine of the longest-line program so it
  // will correctly print the length of arbitrarily long input lines, and as
  // much as possible of the text.

  int len;               /* current line length */
  int max;               /* max length seen so far */
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line saved here */

  max = 0;
  while ((len = get_trimmed_line(line, MAXLINE)) > 0) {
    if (len > LONGLINE) {
      max = len;
      copy(longest, line);
      printf("%d %s", len, line);
    }
  }
}

float ftoc(float fahr) {
  // Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to
  // use a function for conversion.
  return (5.0 / 9.0) * (fahr - 32.0);
}

void char_freq_histogram() {
  // Exercise 1-14. Write a program to print a histogram of different characters
  // in its input.
  int character, index, bars;
  int characters[HIGHESTCHAR];

  for (index = 0; index < HIGHESTCHAR; ++index) {
    characters[index] = 0;
  }

  while ((character = getchar()) != EOF) {
    ++characters[character];
  }

  for (index = 1; index < HIGHESTCHAR; ++index) {
    if (characters[index] > 0) {
      if (index == '\n') {
        printf("nl");
      } else if (index == '\t') {
        printf("tb");
      } else {
        putchar(index);
        printf(" "); // to make single characters take same width as nl and tb
      }
      printf(" ");
      for (bars = 0; bars < characters[index]; ++bars) {
        printf("|");
      }
      printf("\n");
    }
  }
  printf("\n");
}

void word_length_histogram() {
  // Exercise 1-13. Write a program to print a histogram of the lengths of words
  // in its input. It is easy to draw the histogram with the bars horizontal; a
  // vertical orientation is more challenging.
  int character, current_word_length, state, index, bars, longest_word;

  int word_lengths[LONGESTWORD];

  state = OUTWORD;
  longest_word = current_word_length = 0;
  for (index = 0; index < LONGESTWORD; ++index) {
    word_lengths[index] = 0;
  }
  while ((character = getchar()) != EOF) {
    if (state == INWORD) {
      ++current_word_length;
    }
    if (word_lengths[current_word_length] > longest_word) {
      longest_word = word_lengths[current_word_length];
    }
    if (character == ' ' || character == '\n' || character == '\t') {
      ++word_lengths[current_word_length];
      current_word_length = 0;
      state = OUTWORD;
    } else if (state == OUTWORD) {
      state = INWORD;
    }
  }

  // horizontal orientation
  for (index = 1; index < LONGESTWORD; ++index) {
    if (word_lengths[index] > 0) {
      printf("%d ", index);
      for (bars = 0; bars < word_lengths[index]; ++bars) {
        printf("|");
      }
      printf("\n");
    }
  }
  printf("\n");

  // vertical orientation
  for (longest_word = longest_word; longest_word > 0; --longest_word) {
    for (index = 1; index <= LONGESTWORD; ++index) {
      if (word_lengths[index] > 0) {
        if (word_lengths[index] >= longest_word) {
          printf("|");
        } else {
          printf(" ");
        }
      }
    }
    printf("\n");
  }
  for (index = 1; index < LONGESTWORD; ++index) {
    if (word_lengths[index] > 0) {
      printf("%d", index);
    }
  }
  printf("\n");
}

void one_word_per_line() {
  // Exercise 1-12. Write a program that prints its input one word per line.
  int character, num_lines, num_words, num_chars, state;

  state = OUTWORD;
  num_lines = num_words = num_chars = 0;

  while ((character = getchar()) != EOF) {
    ++num_chars;
    putchar(character);
    if (character == '\n')
      ++num_lines;
    if (character == ' ' || character == '\n' || character == '\t') {
      state = OUTWORD;
      putchar('\n');
    } else if (state == OUTWORD) {
      state = INWORD;
      ++num_words;
    }
  }
  printf("%d %d %d\n", num_lines, num_words, num_chars);
}

void count_program() {
  // Example program. count lines, words, and characters in input
  /*
   * Exercise 1-11. How would you test the word count program? What kinds of
  input are most likely to uncover bugs if there are any?
   * test by inputting different file types such as c files and markdown files,
  which contain all of the different special escape characters tabs, backspaces
  and other special characters are likely to uncover any bugs
   */
  int character, num_lines, num_words, num_chars, state;

  state = OUTWORD;
  num_lines = num_words = num_chars = 0;

  while ((character = getchar()) != EOF) {
    ++num_chars;
    if (character == '\n')
      ++num_lines;
    if (character == ' ' || character == '\n' || character == '\t')
      state = OUTWORD;
    else if (state == OUTWORD) {
      state = INWORD;
      ++num_words;
    }
  }
  printf("%d %d %d\n", num_lines, num_words, num_chars);
}

void show_ws_chars() {
  // Exercise 1-10. Write a program to copy its input to its output, replacing
  // each tab by \t, each backspace by \b, and each backslash by \\. This makes
  // tabs and backspaces visible in an unambiguous way.
  int character;

  while ((character = getchar()) != EOF) {
    if (character == '\t') {
      putchar('\\');
      putchar('t');
    } else if (character == '\b') {
      putchar('\\');
      putchar('b');
    } else if (character == '\\') {
      putchar('\\');
      putchar('\\');
    } else {
      putchar(character);
    }
  }
}

void single_blanks_only() {
  // Exercise 1-9. Write a program to copy its input to its output, replacing
  // each string of one or more blanks with a single blank.
  int previous_character, character;

  previous_character = 0;
  while ((character = getchar()) != EOF) {
    if (previous_character == ' ') {
      if (character != ' ') {
        putchar(character);
      }
    } else {
      putchar(character);
    }
    previous_character = character;
  }
}

void count_blanks_tabs_newlines() {
  // Exercise 1-8. Write a program to count blanks, tabs, and newlines.
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

void eof_value() {
  // exercise 1-6 & 1-7
  int c;

  c = getchar();
  while (c != EOF) {
    printf("%d", c != EOF); // 1 or 0
    printf("%d", EOF);      // EOF = -1
    c = getchar();
  }
}

void cels_to_fahr_reverse() {
  // exercise 1-5
  float fahr, celsius;
  float times_by;

  times_by = 9.0 / 5.0;
  celsius = UPPERTEMP;

  printf("Celsius-Fahrenheit table\n");
  while (celsius >= LOWERTEMP) {
    fahr = celsius * times_by + 32;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius - TEMPSTEP;
  }
}

void cels_to_fahr() {
  // exercise 1-4
  float fahr, celsius;
  float times_by;

  times_by = 9.0 / 5.0;
  celsius = LOWERTEMP;

  printf("Celsius-Fahrenheit table\n");
  while (celsius <= UPPERTEMP) {
    fahr = celsius * times_by + 32;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius = celsius + TEMPSTEP;
  }
}

void fahr_to_cels() {
  // exercise 1-3
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;
  fahr = lower;

  printf("Fahrenheit-Celsius table\n");
  while (fahr <= upper) {
    celsius = ftoc(fahr);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}

void unknown_escape_char() {
  // exercise 1-2
  printf("hello, ");
  // printf("\k"); // unknown escape char warning, then prints normal char
  printf("\n");
}

void hello_world() {
  // exercise 1-1
  printf("hello, ");
  printf("world");
  printf("\n");
}
