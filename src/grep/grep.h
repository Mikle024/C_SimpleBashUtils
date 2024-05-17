#ifndef GREP_H
#define GREP_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>

#include "errorProcessingGrep.h"
#include "operationParserGrep.h"

void readFile(char *nameFile, OPER *flags, regex_t *compiledRegular);
void grep(OPER *flags, int argc, char **argv);
void outline(char *line, int quantitySymbol);
void outputMatch(regex_t *compiledRegular, char *line);
void addRegularFromFile(char *nameFile, OPER *flags);

#endif