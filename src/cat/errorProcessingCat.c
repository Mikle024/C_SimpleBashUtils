#include "errorProcessingCat.h"

int illegalShortOption(char option) {
  printf(
      "cat: invalid option -- '%c'\n"
      "Try 'cat --help' for more information.\n",
      option);
  return 1;
}

int illegalLongOption(char *argv) {
  printf(
      "cat: invalid option -- '%s'\n"
      "Try 'cat --help' for more information.\n",
      argv + 2);
  return 1;
}

int noSuchFileError(FILE *file, char *nameFile) {
  int flagError = 0;
  if (file == NULL) {
    printf("cat: %s: ", nameFile);
    fflush(stdout);
    perror("");
    flagError = 1;
  }
  return flagError;
}