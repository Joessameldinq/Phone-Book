#include "../include/searching.h"
#include <string.h>

Entry* binarySearch(Entry entries[], int low, int high, char *target, 
                   int (*cmp)(const Entry*, const Entry*)){
    // Not found - return empty entry
    
    // Create temporary entry for comparison
    Entry temp = {0};
    strcpy(temp.name, target);
    strcpy(temp.phoneNumber, target);
    strcpy(temp.city, target);
    
    while (low <= high) {
        int mid = low + (high - low) / 2;  
        
        int compareResult = cmp(&temp, &entries[mid]);
        
        if(compareResult == 0) {
            return &entries[mid];
        }
        else if (compareResult < 0) {
            high = mid - 1;  
        }
        else {
            low = mid + 1;   
        }
    }
    
    return NULL;  
}
