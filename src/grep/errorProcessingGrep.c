#include "errorProcessingGrep.h"

int noSuchFileError(FILE *file, char *nameFile, OPER *flags) {
  int flagError = 0;
  if (file == NULL) {
    if (!flags->s) {
      printf("grep: %s: ", nameFile);
      fflush(stdout);
      perror("");
    }
    flagError = 1;
  }
  return flagError;
}