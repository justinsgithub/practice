#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1000
#define MAX_LINE_LENGTH 100
#define A_COMMAND 1
#define C_COMMAND 2
#define L_COMMAND 3

void openfile(FILE **f, char *fname, char *mode);

struct prog_files {
  FILE *asmfp;
  FILE *hackfp;
};

struct Code {
  char *(*dest)(char *command);
  char *(*comp)(char *command);
  char *(*jump)(char *command);
};

struct PARSER {
  struct prog_files (*init)(int argc, char *asmfile);
  int (*has_more_commands)(int *line_count);
  void (*advance)(char **command, int *first);
  /* int *command_type(char *command); */
  /* char *symbol(char *command); */
  /* char *dest(char *command); */
  /* char *comp(char *command); */
  /* char *jump(char *command); */
};

struct PARSER Parser();

void filecopy(FILE *, FILE *);
int str_pattern(char str[], char pattern[]);
int get_line(char *line, int max, FILE *infile);
int remove_comments(FILE *file, char program[MAXLINE][MAX_LINE_LENGTH]);
void strip_comment(char *line);
void remove_whitespace(char *line);
