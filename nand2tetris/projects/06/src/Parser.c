#include "Assembler.h"

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
}

void command_type(char *command, int *type) {
  switch (*command) {
  case '@':
    *type = A_COMMAND;
    break;
  case '(':
    *type = L_COMMAND;
    break;
  default:
    *type = C_COMMAND;
    break;
  }
}

void symbol(char *command, char *symbol_str) {
  if (*command++ == '@') {
    while (*command)
      *symbol_str++ = *command++;
    *symbol_str = '\0';
    return;
  }
  while (*command != ')')
    *symbol_str++ = *command++;
  *symbol_str = '\0';
}

void dest(char *command, char *dest_str) {
  char *equal = strchr(command, '=');
  if (!equal) {
    strcpy(dest_str, STRNULL);
    return;
  }
  while (*command != '=')
    *dest_str++ = *command++;
  (*dest_str)++;
  *dest_str = '\0';
}

void jump(char *command, char *jump_str) {
  char *semi = strchr(command, ';');
  if (!semi++) {
    strcpy(jump_str, STRNULL);
    return;
  }
  while (*semi)
    *jump_str++ = *semi++;
  (*jump_str)++;
  *jump_str = '\0';
}

void comp(char *command, char *comp_str) {
  char *equal = strchr(command, '=');
  if (equal++) {
    while (*equal)
      *comp_str++ = *equal++;
    *comp_str = '\0';
    return;
  }
  while (*command != ';')
    *comp_str++ = *command++;
  *comp_str = '\0';
}

struct PARSER Parser() {
  struct PARSER p;

  p.init = init;
  p.has_more_commands = has_more_commands;
  p.advance = advance;
  p.command_type = command_type;
  p.symbol = symbol;
  p.dest = dest;
  p.comp = comp;
  p.jump = jump;
  return p;
}
