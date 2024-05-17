#ifndef OPERATION_PARSER_GREP_H
#define OPERATION_PARSER_GREP_H

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>

typedef struct operation {
  int e, i, v, c, l, n, h, s, f, o;
  char *pattern;
  int lengthPattern;
  int memoryPattern;
} OPER;

OPER flagsParser(int argc, char **argv);
void addPattern(OPER *flags, char *pattern);

#endif