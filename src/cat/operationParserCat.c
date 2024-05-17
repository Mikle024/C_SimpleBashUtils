#include "operationParserCat.h"

int flagsParser(int argc, char **argv, OPER *flags, int *errorFlags) {
  int index = 1;
  for (int i = 1; i < argc; i++) {
    if (isShortOperation(argv[i]))
      index += treatmentShortFlag(argv[i], flags, errorFlags);
    else if (isLongOperation(argv[i]))
      index += treatmentLongFlag(argv[i], flags, errorFlags);
  }
  return index;
}

int isShortOperation(char *arg) { return arg[0] == '-' && arg[1] != '-'; }

int isLongOperation(char *arg) { return arg[0] == '-' && arg[1] == '-'; }

int treatmentShortFlag(char *argv, OPER *flags, int *errorFlags) {
  for (size_t j = 1; j < strlen(argv); j++) {
    switch (argv[j]) {
      case 'b':
        flags->b = 1;
        break;
      case 'e':
        flags->e = 1;
        flags->v = 1;
        break;
      case 'E':
        flags->e = 1;
        break;
      case 'n':
        flags->n = 1;
        break;
      case 's':
        flags->s = 1;
        break;
      case 't':
        flags->t = 1;
        flags->v = 1;
        break;
      case 'T':
        flags->t = 1;
        break;
      case 'v':
        flags->v = 1;
        break;
      default:
        if (!(*errorFlags)) *errorFlags = illegalShortOption(argv[j]);
        break;
    }
  }
  return 1;
}

int treatmentLongFlag(char *argv, OPER *flags, int *errorFlags) {
  for (size_t j = 0; j < strlen(argv); j++) {
    if (strcmp(argv + 2, "number") == 0) {
      flags->n = 1;
    } else if (strcmp(argv + 2, "number-nonblank") == 0) {
      flags->b = 1;
    } else if (strcmp(argv + 2, "squeeze-blank") == 0) {
      flags->s = 1;
    } else {
      *errorFlags = illegalLongOption(argv);
      break;
    }
  }
  return 1;
}