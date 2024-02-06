#include <stdio.h>
#include <string.h>

/* filegets: get at most n chars from iop */
char *filegetline(char *s, int n, FILE *iop) {
  register int c;
  register char *cs;
  cs = s;
  while (--n > 0 && (c = getc(iop)) != EOF)
    if ((*cs++ = c) == '\n')
      break;
  *cs = '\0';
  return (c == EOF && cs == s) ? NULL : s;
}

/* fputs: put string s on file iop */
int fileputs(char *s, FILE *iop) {
  int c;
  while ((c = *s++))
    putc(c, iop);
  return ferror(iop) ? EOF : 0;
}

/* getline: read a line, return length */
int get_line(char *line, int max, FILE *infile) {
  if (fgets(line, max, infile) == NULL)
    return 0;
  else
    return strlen(line);
}
