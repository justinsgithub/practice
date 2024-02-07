#include "Assembler.h"

void openfile(FILE **f, char *fname, char *mode) {
  if ((*f = fopen(fname, mode)) == NULL) {
    printf("fopen failed, errno = %d\n", errno);
    fprintf(stderr, "Assembler: can't open %s\n", fname);
    exit(1);
  }
}

int remove_comments(FILE *file, char lines[MAXLINE][MAX_LINE_LENGTH]) {
  char line[MAX_LINE_LENGTH];
  int line_count = 0;

  // Read lines from the file and store them in the array
  while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
    if (line_count < MAXLINE - 1) {
      strip_comment(line);
      remove_whitespace(line);
      if (strlen(line) > 1) {
        strcpy(lines[line_count], line);
        line_count++;
      }
    } else {
      fprintf(stderr, "Reached maximum number of lines\n");
      break;
    }
  }

  // Print the lines stored in the array
  for (int i = 0; i < line_count; i++) {
    printf("%s", lines[i]);
  }

  return 0;
}

void remove_whitespace(char *line) {
  char *src = line;  // Source pointer for reading
  char *dest = line; // Destination pointer for writing

  // Iterate through the line
  while (*src) {
    // If the character is not a white space (excluding newline), copy it
    if (!isspace(*src) || *src == '\n') {
      *dest++ = *src;
    }
    src++;
  }

  // Add null terminator at the end
  *dest = '\0';
}

void strip_comment(char *line) {
  for (int i = 0;;) {
    if (line[i] == '\n')
      break;
    /* character "/" is only used as comment */
    if (line[i] == '/') {
      line[i++] = '\n';
      line[i] = '\0';
    }
    i++;
  }
}

/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp) {
  unsigned long c;
  char line[1000];
  while ((c = get_line(line, MAXLINE, ifp))) {
    fputs(line, ofp);
  }
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

int get_line(char *line, int max, FILE *infile) {
  if (fgets(line, max, infile) == NULL)
    return 0;
  return strlen(line);
}
