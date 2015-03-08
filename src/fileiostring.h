#ifndef FILEIOSTRING_H
#define FILEIOSTRING_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

// method to wrap open file command
FILE *open_file();
// method to close file
bool close_file(FILE *fp);
// method to write to file
bool write_file(FILE *fp);
#endif