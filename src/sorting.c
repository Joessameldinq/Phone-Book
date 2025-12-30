#include "../include/definitions.h"
#include <string.h>
#include <stdlib.h>

// Helper to swap Entries
static inline void swap(Entry *e1, Entry *e2){
    Entry temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}

// Comparison functions
int compareByName(const Entry *e1, const Entry *e2){
    return strcmp(e1->name, e2->name);
}

int compareByNumber(const Entry *e1, const Entry *e2){
    return strcmp(e1->phoneNumber, e2->phoneNumber);
}

int compareByCity(const Entry *e1, const Entry *e2){
    return strcmp(e1->city, e2->city);
}
int partition(Entry entries[],int low,int high,int (*cmp)(const Entry*, const Entry*))
{
    Entry pivot = entries[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
         int compareResult = cmp(&entries[j],&pivot);
         if(compareResult < 0){
            i++;
            swap(&entries[i], &entries[j]);
        }
    }
    swap(&entries[i+1], &entries[high]);
    return i + 1;
}
void quickSort(Entry entries[],int low,int high,int (*cmp)(const Entry*, const Entry*)){
    if(low < high){
        int pivotIndex = partition(entries, low, high,cmp);
        quickSort(entries, low, pivotIndex - 1,cmp);
        quickSort(entries, pivotIndex + 1, high,cmp);
    }
}
void merge(Entry entries[],int low,int mid,int high,int (*cmp)(const Entry*, const Entry*))
{
    int n1 = mid - low +1;
    int n2 = high - mid;
    Entry *L = (Entry*)malloc(sizeof(Entry) * n1);
    Entry *R = (Entry*)malloc(sizeof(Entry) * n2);


    //Copy Entries contents to temporary arrays
    for(int i = 0 ; i < n1 ; i++){
        L[i] = entries[i+low];
    }
    for(int i = 0 ; i < n2 ; i++){
        R[i] = entries[mid+i+1];
    }

    int i = 0 , k = 0 , index = low;
    while(i < n1 && k  < n2){
        int compareResult = cmp(&L[i],&R[k]);
        if(compareResult < 0){
            entries[index++] = L[i++];
        }
        else
        {
            entries[index++] = R[k++];

        }
    }
    while(i < n1)entries[index++] = L[i++];
    while(k < n2)entries[index++] = R[k++];

    free(L);
    free(R);

}
void mergeSort(Entry entries[],int low ,int high,int (*cmp)(const Entry*, const Entry*)){
    if(low < high){
        int mid = (low + high)/2;
        mergeSort(entries,low,mid,cmp);
        mergeSort(entries,mid+1,high,cmp);
        merge(entries,low,mid,high,cmp);
    }
}