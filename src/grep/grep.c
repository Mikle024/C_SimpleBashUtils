#include "grep.h"

void grep(OPER *flags, int argc, char **argv) {
  regex_t compiledRegular;
  int codeError =
      regcomp(&compiledRegular, flags->pattern, REG_EXTENDED | flags->i);
  if (codeError) perror("Error");
  for (int i = optind; i < argc; i++) {
    readFile(argv[i], flags, &compiledRegular);
  }
  regfree(&compiledRegular);
}

void readFile(char *nameFile, OPER *flags, regex_t *compiledRegular) {
  FILE *file = fopen(nameFile, "rt");
  if (!noSuchFileError(file, nameFile, flags)) {
    char *line = NULL;
    size_t memoryLine = 0;
    int readLine = getline(&line, &memoryLine, file);
    int lineNumber = 1;
    int resultCount = 0;
    while (readLine != -1) {
      int result = regexec(compiledRegular, line, 0, NULL, 0);
      if ((result == 0 && !flags->v) || (flags->v && result != 0)) {
        if (!flags->c && !flags->l) {
          if (!flags->h) printf("%s:", nameFile);
          if (flags->n) printf("%d:", lineNumber);
          if (flags->o && !flags->v) {
            outputMatch(compiledRegular, line);
          } else {
            outline(line, readLine);
          }
        }
        resultCount++;
      }
      readLine = getline(&line, &memoryLine, file);
      lineNumber++;
    }
    free(line);
    if (flags->c && !flags->l) {
      if (!flags->h) printf("%s:", nameFile);
      printf("%d\n", resultCount);
    }
    if (flags->c && flags->l) {
      if (!flags->h) printf("%s:", nameFile);
      if (resultCount > 0)
        printf("1\n");
      else
        printf("0\n");
    }
    if (flags->l && resultCount > 0) printf("%s\n", nameFile);
    fclose(file);
  }
}

void outline(char *line, int quantitySymbol) {
  for (int i = 0; i < quantitySymbol; i++) {
    putchar(line[i]);
  }
  if (line[quantitySymbol - 1] != '\n') putchar('\n');
}

void outputMatch(regex_t *compiledRegular, char *line) {
  regmatch_t match;
  int regularIndex = 0;
  while (1) {
    int result = regexec(compiledRegular, line + regularIndex, 1, &match, 0);
    if (result != 0) break;
    for (int i = match.rm_so; i < match.rm_eo; i++) {
      putchar(line[i]);
    }
    putchar('\n');
    regularIndex += match.rm_eo;
  }
}

void addRegularFromFile(char *nameFile, OPER *flags) {
  FILE *file = fopen(nameFile, "rt");
  if (!noSuchFileError(file, nameFile, flags)) {
    char *line = NULL;
    size_t memoryLine = 0;
    int readLine = getline(&line, &memoryLine, file);
    while (readLine != -1) {
      if (line[readLine - 1] == '\n') line[readLine - 1] = '\0';
      addPattern(flags, line);
      readLine = getline(&line, &memoryLine, file);
    }

    free(line);
    fclose(file);
  }
}