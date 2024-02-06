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
