#ifndef OPERATION_PARSER_CAT_H
#define OPERATION_PARSER_CAT_H

#include <string.h>

#include "errorProcessingCat.h"

typedef struct operation {
  int b, e, n, s, t, v;
} OPER;

int flagsParser(int argc, char **argv, OPER *flags, int *errorFlags);
int isShortOperation(char *arg);
int isLongOperation(char *arg);
int treatmentShortFlag(char *argv, OPER *flags, int *errorFlags);
int treatmentLongFlag(char *argv, OPER *flags, int *errorFlags);

#endif