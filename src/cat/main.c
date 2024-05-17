#include "cat.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    catFromStdin();
  }
  OPER flags = {0};
  int errorFlags = 0;
  int indexFiles = flagsParser(argc, argv, &flags, &errorFlags);

  for (int i = indexFiles; i < argc; i++) {
    if (!errorFlags) readFile(&flags, argv[i]);
  }

  return 0;
}