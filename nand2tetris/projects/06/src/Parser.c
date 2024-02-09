#include "Assembler.h"

struct prog_files init(int argc, char *asmfile);
int has_more_commands(int *lc);
void advance(char **command, int *first);

struct PARSER Parser() {
  struct PARSER p;

  p.init = init;
  p.has_more_commands = has_more_commands;
  p.advance = advance;
  return p;
};

struct prog_files init(int argc, char *asmfile) {
  struct prog_files files;
  char hf[100];
  char *hackfile = hf;

  size_t filename_length;

  if (argc != 2) { /*  should be 2 args; (program name(automatic), asm file)*/
    printf("Usage: Assembler Prog.asm\n");
    exit(1);
  }

  filename_length = strlen(asmfile);
  hackfile = strcpy(hackfile, asmfile);
  hackfile[filename_length - 4] = '\0';
  hackfile = strcat(hackfile, ".hack");

  openfile(&files.asmfp, asmfile, "r");
  openfile(&files.hackfp, hackfile, "w");
  return files;
}

int has_more_commands(int *line_count) {
  if ((*line_count)--)
    return 1;
  return 0;
};

void advance(char **command, int *first) {
  if (!(*first))
    *command += MAX_LINE_LENGTH;
  if (*first == 1)
    (*first) = 0;
};

/* int *command_type(char *command); */
/* char *symbol(char *command); */
/* char *dest(char *command); */
/* char *comp(char *command); */
/* char *jump(char *command); */
