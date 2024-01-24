#define VTAB '\013'   /* octal ASCII vertical tab */
#define BELL '\007'   /* octal ASCII bell character */
#define HEXVTAB '\xb' /* hexadecimal ASCII vertical tab */
#define HEXBELL '\x7' /* hexadecimal ASCII bell character */
#define MAXLINE 1000
char line[MAXLINE + 1];

#define LEAP 1 /* in leap years */
int days[31 + 28 + LEAP + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31];

enum boolean { NO, YES };

enum escapes { _BELL = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n', _VTAB = '\v', RETURN = '\r' };
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC }; /* FEB is 2, MAR is 3, etc. */

/* stringlength: return length of s */
int stringlength(char s[]) {
  int i;
  i = 0;
  while (s[i] != '\0')
    ++i;
  return i;
}
