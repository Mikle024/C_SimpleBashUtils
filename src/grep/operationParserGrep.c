#include "operationParserGrep.h"

#include "grep.h"

OPER flagsParser(int argc, char **argv) {
  OPER flags = {0};
  int opt;
  struct option longOption[] = {
      {"e", required_argument, NULL, 'e'}, {"i", no_argument, NULL, 'i'},
      {"v", no_argument, NULL, 'v'},       {"c", no_argument, NULL, 'c'},
      {"l", no_argument, NULL, 'l'},       {"n", no_argument, NULL, 'n'},
      {"h", no_argument, NULL, 'h'},       {"s", no_argument, NULL, 's'},
      {"f", required_argument, NULL, 'f'}, {"o", no_argument, NULL, 'o'},
      {NULL, no_argument, NULL, 0},
  };
  while ((opt = getopt_long(argc, argv, "e:ivclnhsf:o", longOption, NULL)) !=
         -1) {
    switch (opt) {
      case 'e':
        flags.e = 1;
        addPattern(&flags, optarg);
        break;
      case 'i':
        flags.i = REG_ICASE;
        break;
      case 'v':
        flags.v = 1;
        break;
      case 'c':
        flags.c = 1;
        break;
      case 'l':
        flags.l = 1;
        break;
      case 'n':
        flags.n = 1;
        break;
      case 'h':
        flags.h = 1;
        break;
      case 's':
        flags.s = 1;
        break;
      case 'f':
        flags.f = 1;
        addRegularFromFile(optarg, &flags);
        break;
      case 'o':
        flags.o = 1;
        break;
    }
  }
  if (flags.lengthPattern == 0) addPattern(&flags, argv[optind++]);
  if (argc - optind == 1) flags.h = 1;
  return flags;
}

void addPattern(OPER *flags, char *pattern) {
  int lengthCountPattern = strlen(pattern);
  if (flags->lengthPattern == 0) {
    flags->pattern = malloc(1024 * sizeof(char));
    flags->memoryPattern = 1024;
  }
  if (flags->memoryPattern < flags->lengthPattern + lengthCountPattern) {
    flags->pattern = realloc(flags->pattern, flags->memoryPattern * 2);
  }
  if (flags->lengthPattern != 0) {
    strcat(flags->pattern + flags->lengthPattern, "|");
    flags->lengthPattern++;
  }
  flags->lengthPattern +=
      sprintf(flags->pattern + flags->lengthPattern, "(%s)", pattern);
}