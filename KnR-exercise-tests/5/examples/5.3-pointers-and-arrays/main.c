/* strlen: return length of string s */
int stringlength(char *s) {
  int n;
  for (n = 0; *s != '\0'; s++)
    n++;
  return n;
}
