#include "chap1.c"
#include "chap2.c"
#include "chap3.c"

int main() {
  /* Chapter 1 */
  /* three forward slashes is for testing script */

  // hello_world();
  // unknown_escape_char();
  // fahr_to_cels();
  // cels_to_fahr();
  // cels_to_fahr_reverse();
  // eof_value();
  // count_blanks_tabs_newlines();
  // single_blanks_only();
  // show_ws_chars();
  // count_program();
  // one_word_per_line();
  // char_freq_histogram();
  // print_long_lines();
  // longer_than_80();
  // trim_lines();
  // detab();
  // entab();
  // fold();

  /* Chapter 2 */
  // type_ranges();
  // no_logic_ops();
  const char hexstring[] = "1B";
  char fromthis[] = "has1has1has1";
  const char deletethese[] = "1s";
  // hextoint(hexstring);
  // squeeze(fromthis, deletethese);
  // any(fromthis, deletethese);
  // lower('C');
  char escapefrom[] = "blah\\tblah\tha	ha\nha";
  char escapeto[100];
  char realfrom[] = "blah\\tblah\tha\\nha\nha";
  char realto[100];
  // escape(escapeto, escapefrom);
  /// real(realto, realfrom);
}
