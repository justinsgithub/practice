#define LOWERTEMP 0
#define UPPERTEMP 300
#define TEMPSTEP 10
#define INWORD 1
#define OUTWORD 0
#define LONGESTWORD 30
#define HIGHESTCHAR 255 /* max length char array could be ( practically speaking for this exercise ) */
#define MAXLINE 1000    /* maximum input line size */
#define LONGLINE 81     /* long input line size */
#define PRINTSIZE 81    /* minimum input line size to print */

void hello_world();
void unknown_escape_char();
void fahr_to_cels();
void cels_to_fahr();
void cels_to_fahr_reverse();
void eof_value();
void count_blanks_tabs_newlines();
void single_blanks_only();
void show_ws_chars();
void count_program();
void one_word_per_line();
void char_freq_histogram();
float ftoc(float fahr);
void copy(char to[], char from[]);
int get_line(char line[], int maxline);
void print_long_lines();
void longer_than_80();
int is_special_char(int c);
int trim_line(char line[], int line_len);
void trim_lines();
void reverse(char to[], char from[], int len);
void detab(unsigned short tabstop);
