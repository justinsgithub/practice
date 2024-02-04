#include "Assembler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int main(int argc, char *argv[]) {
  FILE *fp1, *fp2;
  void filecopy(FILE *, FILE *);
  char *prog = argv[0];    /* program name for errors */
  char *asmfile = argv[1]; /* file to assemble */
  char hf[100];
  char *hackfile = hf;

  size_t filename_length;

  if (argc != 2) { /*  should be 2 args; (program name(automatic), asm file)*/
    printf("Usage: Assembler Prog.asm\n");
    return 0;
  }

  filename_length = strlen(asmfile);
  hackfile = strcpy(hackfile, asmfile);
  hackfile[filename_length - 4] = '\0';
  hackfile = strcat(hackfile, ".hack");

  if ((fp1 = fopen(*++argv, "r")) == NULL) {
    fprintf(stderr, "%s: can't open %s\n", prog, *argv);
    exit(1);
  }
  if ((fp2 = fopen(hackfile, "w")) == NULL) {
    fprintf(stderr, "%s: can't open %s\n", prog, hackfile);
    exit(1);
  }
  filecopy(fp1, fp2);
  fclose(fp1);
  fclose(fp2);
  if (ferror(stdout)) {
    fprintf(stderr, "%s: error writing stdout\n", prog);
    exit(2);
  }
  exit(0);
}

/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp) {
  int c;
  while ((c = getc(ifp)) != EOF)
    putc(c, ofp);
}

int str_pattern(char str[], char pattern[]) {
  int i, j, k;
  int ri = -1; // right most index (-1 if not found)

  for (i = 0; str[i] != '\0'; i++) {
    for (j = i, k = 0; pattern[k] != '\0' && str[j] == pattern[k]; j++, k++)
      ;
    if (k > 0 && pattern[k] == '\0') {
      ri = i;
    }
  }
  return ri;
}
