#ifndef SORTING_H
#define SORTING_H

#include "definitions.h"
int partition(Entry entries[],int low,int high,int (*cmp)(const Entry*, const Entry*));
//===================================================
int quickSort(Entry entries[],int low,int high,int (*cmp)(const Entry*, const Entry*));
//===================================================
void merge(Entry entries[],int low,int mid,int high,int (*cmp)(const Entry*, const Entry*));
//===================================================
void mergeSort(Entry entries[],int low ,int high,int (*cmp)(const Entry*, const Entry*));
//===================================================
int compareByName(const Entry *e1, const Entry *e2);

int compareByNumber(const Entry *e1, const Entry *e2);

int compareByCity(const Entry *e1, const Entry *e2);




#endif