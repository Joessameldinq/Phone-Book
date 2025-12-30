#ifndef FILE_IO_H
#define FILE_IO_H

#include "definitions.h"
#include <stdio.h>

Entry* readEntries(FILE *fptr,int *returnSize);
void writeEntries(FILE *fptr,Entry entries[],int size);


#endif