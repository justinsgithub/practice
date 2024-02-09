#include "Assembler.h"

int main(int argc, char *argv[]) {
  struct PARSER parser = Parser();
  struct prog_files fp = parser.init(argc, argv[1]); /* think is okay ? */
  char lines[MAXLINE][MAX_LINE_LENGTH];
  char *prog = argv[0]; /* program name for errors */
  int first = 1;

  int line_count = remove_comments(fp.asmfp, lines);
  char *command = lines[0]; /* hacky, need array to start at less than 0 for advance()*/
  while (parser.has_more_commands(&line_count)) {
    parser.advance(&command, &first);
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
