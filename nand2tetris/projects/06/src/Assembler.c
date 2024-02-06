#include "Assembler.h"

int main(int argc, char *argv[]) {
  struct prog_files fp;
  char lines[MAXLINE][MAX_LINE_LENGTH];
  char *blah;
  FILE *asmfp, *hackfp;
  char *prog = argv[0]; /* program name for errors */
  fp = init(argc, argv[1]);

  remove_comments(fp.asmfp, lines);

  // blah = fp.blah; /* needs assigned to variable to use properly ? */
  // filecopy(fp.asmfp, fp.hackfp);
  fclose(fp.asmfp);
  fclose(fp.hackfp);
  if (ferror(stdout)) {
    fprintf(stderr, "%s: error writing stdout\n", prog);
    exit(2);
  }
  exit(0);
}
