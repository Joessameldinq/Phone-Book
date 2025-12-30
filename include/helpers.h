#ifndef HELPERS_H
#define HELPERS_H

#include "definitions.h"
void displayEntries(Entry entries[], int size);
void clearScreen();
int mainMenu();
int sortingAlgorithmMenu();
int sortFieldMenu();
int searchFieldMenu();
char* readString();
#endif