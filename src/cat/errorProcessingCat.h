#ifndef ERROR_PROCESSING_CAT_H
#define ERROR_PROCESSING_CAT_H

#include <stdio.h>

int illegalShortOption(char option);
int illegalLongOption(char *argv);
int noSuchFileError(FILE *file, char *nameFile);

#endif