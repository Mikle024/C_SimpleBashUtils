#ifndef CAT_H
#define CAT_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

#include "errorProcessingCat.h"
#include "operationParserCat.h"

void outLine(OPER *flags, char *line, int quantitySymbol);
void output(OPER *flags, char *line, int *lineNumber, int *emptyLine,
            int quantitySymbol);
void readFile(OPER *flags, char *nameFile);
char outFlagV(char currentChar);
void catFromStdin();

#endif