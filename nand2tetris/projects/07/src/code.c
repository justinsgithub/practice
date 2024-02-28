#include "Assembler.h"
#include <string.h>

static char *dest(char *deststr, char *destbits) {
  if (!strcmp(deststr, "M"))
    return strcpy(destbits, "001");
  if (!strcmp(deststr, "D"))
    return strcpy(destbits, "010");
  if (!strcmp(deststr, "MD"))
    return strcpy(destbits, "011");
  if (!strcmp(deststr, "A"))
    return strcpy(destbits, "100");
  if (!strcmp(deststr, "AM"))
    return strcpy(destbits, "101");
  if (!strcmp(deststr, "AD"))
    return strcpy(destbits, "110");
  if (!strcmp(deststr, "AMD"))
    return strcpy(destbits, "111");
  return strcpy(destbits, "000");
}

static char *jump(char *jumpstr, char *jumpbits) {
  if (!strcmp(jumpstr, "JGT"))
    return strcpy(jumpbits, "001");
  if (!strcmp(jumpstr, "JEQ"))
    return strcpy(jumpbits, "010");
  if (!strcmp(jumpstr, "JGE"))
    return strcpy(jumpbits, "011");
  if (!strcmp(jumpstr, "JLT"))
    return strcpy(jumpbits, "100");
  if (!strcmp(jumpstr, "JNE"))
    return strcpy(jumpbits, "101");
  if (!strcmp(jumpstr, "JLE"))
    return strcpy(jumpbits, "110");
  if (!strcmp(jumpstr, "JMP"))
    return strcpy(jumpbits, "111");
  return strcpy(jumpbits, "000");
}

static char *comp(char *compstr, char *compbits) {
  if (!strcmp(compstr, "1"))
    return strcpy(compbits, "0111111");
  if (!strcmp(compstr, "-1"))
    return strcpy(compbits, "0111010");
  if (!strcmp(compstr, "D"))
    return strcpy(compbits, "0001100");
  if (!strcmp(compstr, "A"))
    return strcpy(compbits, "0110000");
  if (!strcmp(compstr, "!D"))
    return strcpy(compbits, "0001101");
  if (!strcmp(compstr, "!A"))
    return strcpy(compbits, "0110001");
  if (!strcmp(compstr, "-D"))
    return strcpy(compbits, "0001111");
  if (!strcmp(compstr, "-A"))
    return strcpy(compbits, "0110011");
  if (!strcmp(compstr, "D+1"))
    return strcpy(compbits, "0011111");
  if (!strcmp(compstr, "A+1"))
    return strcpy(compbits, "0110111");
  if (!strcmp(compstr, "D-1"))
    return strcpy(compbits, "0001110");
  if (!strcmp(compstr, "A-1"))
    return strcpy(compbits, "0110010");
  if (!strcmp(compstr, "D+A"))
    return strcpy(compbits, "0000010");
  if (!strcmp(compstr, "D-A"))
    return strcpy(compbits, "0010011");
  if (!strcmp(compstr, "A-D"))
    return strcpy(compbits, "0000111");
  if (!strcmp(compstr, "D&A"))
    return strcpy(compbits, "0000000");
  if (!strcmp(compstr, "D|A"))
    return strcpy(compbits, "0010101");
  if (!strcmp(compstr, "M"))
    return strcpy(compbits, "1110000");
  if (!strcmp(compstr, "!M"))
    return strcpy(compbits, "1110001");
  if (!strcmp(compstr, "-M"))
    return strcpy(compbits, "1110011");
  if (!strcmp(compstr, "M+1"))
    return strcpy(compbits, "1110111");
  if (!strcmp(compstr, "M-1"))
    return strcpy(compbits, "1110010");
  if (!strcmp(compstr, "D+M"))
    return strcpy(compbits, "1000010");
  if (!strcmp(compstr, "D-M"))
    return strcpy(compbits, "1010011");
  if (!strcmp(compstr, "M-D"))
    return strcpy(compbits, "1000111");
  if (!strcmp(compstr, "D&M"))
    return strcpy(compbits, "1000000");
  if (!strcmp(compstr, "D|M"))
    return strcpy(compbits, "1010101");
  return strcpy(compbits, "0101010");
}

struct CODE Code() {
  struct CODE code;
  code.dest = dest;
  code.comp = comp;
  code.jump = jump;
  return code;
};
