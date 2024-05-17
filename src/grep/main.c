#include "grep.h"

int main(int argc, char *argv[]) {
  if (argc > 2) {
    OPER flags = flagsParser(argc, argv);
    grep(&flags, argc, argv);
    free(flags.pattern);
  }

  return 0;
}