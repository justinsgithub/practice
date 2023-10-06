#include <stdio.h>

int main() {
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
