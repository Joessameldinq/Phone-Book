#include "../include/fileio.h"
#include <string.h>
#include <stdlib.h>


Entry* readEntries(FILE *fptr, int *returnSize)
{
    int counter = 0;
    char temp[200];
    Entry *entries = (Entry*)malloc(sizeof(Entry) * 1005);
    
    if(!entries) {
        fprintf(stderr, "Memory allocation failed\n");
        *returnSize = 0;
        return NULL;
    }
    //Skip header
    if(!fgets(temp, 200, fptr)) {
        fprintf(stderr, "Warning: Empty file\n");
        free(entries);
        fclose(fptr);
        *returnSize = 0;
        return NULL;
    }
    // Read data lines
    while (fgets(temp, 200, fptr) && counter < 1005)
    {
        // Remove newline if present
        temp[strcspn(temp, "\n")] = '\0';
        temp[strcspn(temp, "\r")] = '\0';
        
        int i = 0;
        char *token = strtok(temp, ",");
        
        while(token && i < 3) {
            // Trim leading/trailing spaces
            while(*token == ' ') token++;
            char *end = token + strlen(token) - 1;
            while(end > token && *end == ' ') end--;
            *(end + 1) = '\0';
            
            switch (i)
            {
            case 0:  // Name
                strncpy(entries[counter].name, token, sizeof(entries[counter].name) - 1);
                entries[counter].name[sizeof(entries[counter].name) - 1] = '\0';
                break;
            case 1:  // Phone Number
                strncpy(entries[counter].phoneNumber, token, sizeof(entries[counter].phoneNumber) - 1);
                entries[counter].phoneNumber[sizeof(entries[counter].phoneNumber) - 1] = '\0';
                break;
            case 2:  // City
                strncpy(entries[counter].city, token, sizeof(entries[counter].city) - 1);
                entries[counter].city[sizeof(entries[counter].city) - 1] = '\0';
                break;
            default:
                break;
            }
            
            token = strtok(NULL, ",");
            i++;
        }
        
        counter++;
    }
    
    *returnSize = counter;
    return entries;
}
void writeEntries(FILE *fptr, Entry entries[], int size)
{
    if(!fptr || !entries) {
        fprintf(stderr, "Error: Invalid file pointer or entries array\n");
        return;
    }
    
    // Write header
    fprintf(fptr, "Name,Phone Number,City\n");
    
    // Write each entry
    for(int i = 0; i < size; i++) {
        fprintf(fptr, "%s,%s,%s\n", 
                entries[i].name,
                entries[i].phoneNumber,
                entries[i].city);
    }
}