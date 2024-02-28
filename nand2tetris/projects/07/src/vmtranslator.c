#include "Assembler.h"

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
  Constructor();
  int rom_count = 0;
  int var_count = 16;

  int line_count = remove_comments(fp.asmfp, lines);
  char *command = lines[0];

  for (int i; i < line_count; i++) {
    char *c = lines[i];
    parser.command_type(c, &type);
    switch (type) {
    case C_COMMAND:
      rom_count++;
      break;
    case A_COMMAND:
      rom_count++;
      break;
    case L_COMMAND:
      parser.symbol(c, symbol_str);
      if (!contains(symbol_str))
        add_entry(symbol_str, rom_count);
      break;
    default:
      break;
    }
  }

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
      break;
    case A_COMMAND:
      parser.symbol(command, symbol_str);
      if (!is_num(symbol_str)) {
        if (!contains(symbol_str))
          add_entry(symbol_str, var_count++);
        sprintf(symbol_str, "%d", get_address(symbol_str));
      }
      ainstruction = decimal_to_binary(symbol_str);
      strcat(ainstruction, "\n");
      fputs(ainstruction, fp.hackfp);
      break;
    case L_COMMAND:
      break;
    default:
      break;
    }
  }
  fclose(fp.asmfp);
  fclose(fp.hackfp);
  exit(0);
}
