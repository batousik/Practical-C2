#ifndef FILEIOSTRING_H
#define FILEIOSTRING_H
#define _BSD_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// method to wrap open file command
FILE *open_file(char *f_rel_name, char *mode);
// method to close file
bool close_file(FILE *fp);
// method to write to file
bool write_file(FILE *fp);
char *getString(FILE* fp, int size);
#endif