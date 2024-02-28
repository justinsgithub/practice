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

  return line_count;
}

void remove_whitespace(char *line) {
  char *src = line;  // Source pointer for reading
  char *dest = line; // Destination pointer for writing

  // Iterate through the line
  while (*src) {
    // If the character is not a white space (excluding newline), copy it
    if (!isspace(*src)) {
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

char *concat(char *base, ...) {
  char *str;
  va_list strings;

  va_start(strings, base);
  while ((str = va_arg(strings, char *))) {
    if (!(strcmp(str, STRNULL)))
      break;
    strcat(base, str);
  }

  va_end(strings);
  return base;
}

// Function to convert decimal string to 16-bit binary representation
char *decimal_to_binary(char *decimal_str) {
  long decimal_val = strtol(decimal_str, NULL, 10); // Convert string to long integer
  // Allocate memory for binary representation (16 bits + null terminator)
  char *binary = (char *)malloc(17 * sizeof(char));

  if (binary == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return NULL;
  }

  binary[16] = '\0'; // Null terminator

  // Convert decimal value to binary representation
  for (int i = 15; i >= 0; i--) {
    binary[i] = (decimal_val & 1) ? '1' : '0';
    decimal_val >>= 1;
  }

  return binary;
}

int is_num(const char *str) {
  char *endptr;
  strtol(str, &endptr, 10); // Attempt to convert string to a long integer

  // Check if conversion failed (no digits found or invalid number)
  if (errno == ERANGE || *endptr != '\0') {
    return 0; // Not a number
  }

  return 1; // Is a number
}
