#include <ctype.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 30000
#define MAX_LINE_LENGTH 100
#define A_COMMAND 1
#define C_COMMAND 2
#define L_COMMAND 3
#define STRNULL "null"
#define MAXSYMBOLS 1000 /* ? don't think num of symbols in program would go past this (pong has 500+)*/

struct Symbol {
  char *symbol;
  int address;
};

void add_entry(char *symbol, int address);
int contains(char *symbol);
int get_address(char *symbol);
void Constructor();

void openfile(FILE **f, char *fname, char *mode);

struct prog_files {
  FILE *asmfp;
  FILE *hackfp;
};

struct CODE {
  char *(*dest)(char *deststr, char *destbits);
  char *(*comp)(char *compstr, char *compbits);
  char *(*jump)(char *jumpstr, char *jumpbits);
};

struct CODE Code();

struct PARSER {
  struct prog_files (*init)(int argc, char *asmfile);
  int (*has_more_commands)(int *line_count);
  void (*advance)(char **command, int *first);
  void (*command_type)(char *command, int *type);
  void (*symbol)(char *command, char *symbol_str);
  void (*dest)(char *command, char *dest_str);
  void (*jump)(char *command, char *jump_str);
  void (*comp)(char *command, char *comp_str);
};

struct PARSER Parser();

void filecopy(FILE *, FILE *);
int str_pattern(char str[], char pattern[]);
int get_line(char *line, int max, FILE *infile);
int remove_comments(FILE *file, char program[MAXLINE][MAX_LINE_LENGTH]);
void strip_comment(char *line);
void remove_whitespace(char *line);
char *concat(char *base, ...);
char *decimal_to_binary(char *decimal_str);
int is_num(const char *str);
