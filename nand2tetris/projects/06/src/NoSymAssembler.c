#include "Assembler.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  struct PARSER parser = Parser();
  struct CODE code = Code();
  struct prog_files fp = parser.init(argc, argv[1]); /* think is okay ? */
  char lines[MAXLINE][MAX_LINE_LENGTH];
  char *prog = argv[0]; /* program name for errors */
  int first = 1;
  int type;
  char symbol_str[20]; /* 20 is max length symbol name or decimal num could be (way over estimate)*/
  char deststr[6];
  char compstr[6];
  char jumpstr[6];
  char destbits[4];
  char compbits[8];
  char jumpbits[4];
  char cinstruction[18]; /* 18 is 16 bits plus \n and \0*/
  char *ainstruction = (char *)malloc(18 * sizeof(char));

  int line_count = remove_comments(fp.asmfp, lines);
  char *command = lines[0];

  while (parser.has_more_commands(&line_count)) {
    strcpy(cinstruction, "111"); /* reset each loop to create instructtion */
    parser.advance(&command, &first);
    parser.command_type(command, &type);
    switch (type) {
    case C_COMMAND:
      parser.dest(command, deststr);
      parser.jump(command, jumpstr);
      parser.comp(command, compstr);
      code.dest(deststr, destbits);
      code.jump(jumpstr, jumpbits);
      code.comp(compstr, compbits);
      concat(cinstruction, compbits, destbits, jumpbits, STRNULL);
      strcat(cinstruction, "\n");
      fputs(cinstruction, fp.hackfp);
      printf("deststr = %s\n", deststr);
      printf("jumpstr = %s\n", jumpstr);
      printf("compstr = %s\n", compstr);
      printf("cinstruction = %s\n", cinstruction);
      break;
    default:
      parser.symbol(command, symbol_str);
      printf("symbolstr = %s\n", symbol_str);
      ainstruction = decimal_to_binary(symbol_str);
      strcat(ainstruction, "\n");
      fputs(ainstruction, fp.hackfp);
      break;
    }
  }

  // filecopy(fp.asmfp, fp.hackfp);
  fclose(fp.asmfp);
  fclose(fp.hackfp);
  if (ferror(stdout)) {
    fprintf(stderr, "%s: error writing stdout\n", prog);
    exit(2);
  }
  exit(0);
}
