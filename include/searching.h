#ifndef SEARCHING_H
#define SEARCHING_H


#include "definitions.h"
Entry* binarySearch(Entry entries[], int low, int high, char *target, 
                   int (*cmp)(const Entry*, const Entry*));
#endif