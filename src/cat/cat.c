#include "cat.h"

#if defined(__APPLE__) || defined(__MACH__)
void readFile(OPER *flags, char *nameFile) {
  FILE *file = fopen(nameFile, "rt");
  if (!noSuchFileError(file, nameFile)) {
    char *line = NULL;
    size_t memoryLine = 0;
    int readLine = getline(&line, &memoryLine, file);
    int lineNumber = 1;
    int emptyLine = 0;
    while (readLine != -1) {
      output(flags, line, &lineNumber, &emptyLine, readLine);
      readLine = getline(&line, &memoryLine, file);
    }
    free(line);
    fclose(file);
  }
}

#elif defined(__linux__)
void readFile(OPER *flags, char *nameFile, int *lineNumber) {
  FILE *file = fopen(nameFile, "rt");
  if (!noSuchFileError(file, nameFile)) {
    char *line = NULL;
    size_t memoryLine = 0;
    int readLine = getline(&line, &memoryLine, file);

    int emptyLine = 0;
    while (readLine != -1) {
      output(flags, line, lineNumber, &emptyLine, readLine);
      readLine = getline(&line, &memoryLine, file);
    }
    free(line);
    fclose(file);
  }
}

#endif

void output(OPER *flags, char *line, int *lineNumber, int *emptyLine,
            int quantitySymbol) {
  if (line[0] == '\n') {
    *emptyLine += 1;
  } else {
    *emptyLine = 0;
  }
  if (flags->s && *emptyLine > 1) {
  } else {
    if (flags->b || flags->n) {
      if (flags->b && line[0] != '\n') {
        printf("%6d\t", *lineNumber);
        *lineNumber += 1;
      }
#if defined(__APPLE__) || defined(__MACH__)
      else if (flags->b && flags->e && line[0] == '\n') {
        printf("      \t");
      }

#endif

      else if (flags->n && !(flags->b)) {
        printf("%6d\t", *lineNumber);
        *lineNumber += 1;
      }
    }
    outLine(flags, line, quantitySymbol);
  }
}

void outLine(OPER *flags, char *line, int quantitySymbol) {
  for (int i = 0; i < quantitySymbol; i++) {
    if (flags->e && line[i] == '\n') putchar('$');
    if (flags->t && line[i] == '\t') {
      printf("^I");
      continue;
    }
    if (flags->v) line[i] = outFlagV(line[i]);
    putchar(line[i]);
  }
}

char outFlagV(char currentChar) {
  if (currentChar == '\n' || currentChar == '\t') return currentChar;
  if (currentChar < 0) {
    printf("M-");
    currentChar = currentChar & 0x7F;
  }
  if (currentChar <= 31) {
    putchar('^');
    currentChar += 64;
  } else if (currentChar == 127) {
    putchar('^');
    currentChar = '?';
  }
  return currentChar;
}

void catFromStdin() {
  char c;
  while (1) {
    scanf("%c", &c);
    putchar(c);
    if (c == 3) break;
  }
}