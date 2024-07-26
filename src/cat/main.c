#include "cat.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    catFromStdin();
  }
  OPER flags = {0};
  int errorFlags = 0;
  int indexFiles = flagsParser(argc, argv, &flags, &errorFlags);

#if defined(__APPLE__) || defined(__MACH__)
  for (int i = indexFiles; i < argc; i++) {
    if (!errorFlags) readFile(&flags, argv[i]);
  }

#elif defined(__linux__)
  int lineNumber = 1;
  for (int i = indexFiles; i < argc; i++) {
    if (!errorFlags) readFile(&flags, argv[i], &lineNumber);
  }

#endif

  return 0;
}