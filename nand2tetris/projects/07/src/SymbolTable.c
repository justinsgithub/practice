#include "Assembler.h"

static struct Symbol *symboltable[MAXSYMBOLS]; /* pointer table */
static int symbolcount = 0;

void add_entry(char *symbol, int address) {
  struct Symbol *sym;
  sym = (struct Symbol *)malloc(sizeof(*sym));
  sym->symbol = strdup(symbol);
  sym->address = address;
  symboltable[symbolcount] = sym;
  symbolcount++;
}

int contains(char *symbol) {
  for (int i = 0; i < symbolcount; i++) {
    if (!strcmp((symboltable[i]->symbol), symbol))
      return 1;
  }
  return 0;
}

int get_address(char *symbol) {
  // printf("%s\n", symbol);
  // printf("%d\n", symbolcount);
  for (int i = 0; i < symbolcount; i++) {
    // printf("%s", symboltable[i]->symbol);
    if (!(strcmp(symboltable[i]->symbol, symbol)))
      return (symboltable[i]->address);
  }
  return 0;
}

void Constructor() {
  struct Symbol symbols[] = {
      "SP",  0,  "LCL", 1,  "ARG", 2,  "THIS", 3,  "THAT", 4,  "R0",     0,     "R1",  1,     "R2",  2,
      "R3",  3,  "R4",  4,  "R5",  5,  "R6",   6,  "R7",   7,  "R8",     8,     "R9",  9,     "R10", 10,
      "R11", 11, "R12", 12, "R13", 13, "R14",  14, "R15",  15, "SCREEN", 16384, "KBD", 24576,
  };
  for (int i = 0; i < 23; i++) {
    add_entry(symbols[i].symbol, symbols[i].address);
  }
}
