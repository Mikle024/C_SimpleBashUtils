#ifndef ERROR_PROCESSING_GREP_H
#define ERROR_PROCESSING_GREP_H

#include <stdio.h>

#include "operationParserGrep.h"

int noSuchFileError(FILE *file, char *nameFile, OPER *flags);

#endif