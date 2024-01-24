/* strcpy: copy t to s; array subscript version */
void strcpyv0(char *s, char *t) {
  int i;
  i = 0;
  while ((s[i] = t[i]) != '\0')
    i++;
}

/* strcpy: copy t to s; pointer version 1 */
void strcpyv1(char *s, char *t) {
  while ((*s = *t) != '\0') {
    s++;
    t++;
  }
}

/* strcpy: copy t to s; pointer version 2 */
void strcpyv2(char *s, char *t) {
  while ((*s++ = *t++) != '\0')
    ;
}

/* strcpy: copy t to s; pointer version 3 */
void strcpyv3(char *s, char *t) {
  while ((*s++ = *t++))
    ;
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmpv0(char *s, char *t) {
  int i;
  for (i = 0; s[i] == t[i]; i++)
    if (s[i] == '\0')
      return 0;
  return s[i] - t[i];
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t; pointer version */
int strcmpv1(char *s, char *t) {
  for (; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}
