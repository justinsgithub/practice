#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1000
#define MAX_LINE_LENGTH 100

void openfile(FILE **f, char *fname, char *mode);

struct prog_files {
  FILE *asmfp;
  FILE *hackfp;
};

struct prog_files init(int argc, char *asmfile);

void filecopy(FILE *, FILE *);
int str_pattern(char str[], char pattern[]);
int get_line(char *line, int max, FILE *infile);
int remove_comments(FILE *file, char lines[MAXLINE][MAX_LINE_LENGTH]);
