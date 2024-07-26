#ifndef CAT_H
#define CAT_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

#include "errorProcessingCat.h"
#include "operationParserCat.h"

#if defined(__APPLE__) || defined(__MACH__)
void readFile(OPER *flags, char *nameFile);

#elif defined(__linux__)
void readFile(OPER *flags, char *nameFile, int *lineNumber);

#endif

void outLine(OPER *flags, char *line, int quantitySymbol);
void output(OPER *flags, char *line, int *lineNumber, int *emptyLine,
            int quantitySymbol);
char outFlagV(char currentChar);
void catFromStdin();

#endif