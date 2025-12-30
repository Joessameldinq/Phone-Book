#include "../include/definitions.h"
#include "../include/searching.h"
#include "../include/sorting.h"
#include "../include/fileio.h"
#include "../include/helpers.h"
#include <stdbool.h>
#include <stdlib.h>

typedef enum{
    MAIN_MENU,
    SORTING,
    SEARCHING,
    DISPLAY_DATA
}AppScreen;


int main(){
    FILE *fptr = fopen("phonebook.csv","r");
    int sizeofentries;
    Entry *entries = readEntries(fptr,&sizeofentries);
    bool appRunning= true;
    AppScreen currentScreen = MAIN_MENU;
    
    while(appRunning){
        switch (currentScreen)
        {
        case MAIN_MENU:
            int choice = mainMenu();
            switch (choice)
            {
            case 1:
                currentScreen = SORTING;
                break;
            case 2:
                currentScreen = SEARCHING;
                break;
            case 3:
                currentScreen = DISPLAY_DATA;
                break;
            default:
                appRunning = false;
                break;
            }
            break;
        case SORTING:
            int sortChoice = sortingAlgorithmMenu();
            bool isQuickSort = true;
            if(sortChoice == 1)
                isQuickSort = false;
            else if(sortChoice == 3)
                {
                    currentScreen = MAIN_MENU;
                    break;
                }
            int fieldSortChoice = sortFieldMenu();
            switch (fieldSortChoice)
            {
            case 1:
                if(isQuickSort)
                    quickSort(entries,0,sizeofentries-1,&compareByName);
                else
                    mergeSort(entries,0,sizeofentries-1,&compareByName);
                break;
            case 2:
                if(isQuickSort)
                    quickSort(entries,0,sizeofentries-1,&compareByCity);
                else
                    mergeSort(entries,0,sizeofentries-1,&compareByCity);
                break;
            case 3:
                if(isQuickSort)
                    quickSort(entries,0,sizeofentries-1,&compareByNumber);
                else
                    mergeSort(entries,0,sizeofentries-1,&compareByNumber);
                break;
            case 4:
                currentScreen = SORTING;
                break;
            default:
                currentScreen = SORTING;
                break;
            }
            displayEntries(entries,sizeofentries);
            printf("Enter the file name you want to save this data\n");
            char *temp = readString();
            
            FILE *fptrSaveData1 = fopen(temp,"w");
            writeEntries(fptrSaveData1,entries,sizeofentries);
            fclose(fptrSaveData1);
            currentScreen = MAIN_MENU;
            free(temp);
            break;
        case SEARCHING:
            int searchChoice = searchFieldMenu();
            Entry *e;
            switch (searchChoice)
            {
            case 1://Byname
                printf("Enter the name you want to search:\n");
                char *searchname = readString();
                quickSort(entries,0,sizeofentries-1,&compareByName);
                e = binarySearch(entries,0,sizeofentries,searchname,&compareByName);
                if(e)
                    printf("%25s,%25s,%25s\n",e->name,e->phoneNumber,e->city);
                else
                    printf("Not Found\n");
                free(searchname);
                break;
            case 2://Phone Number
                printf("Enter the Phone number you want to search:\n");
                char *phoneNumber = readString();
                quickSort(entries,0,sizeofentries-1,&compareByNumber);
                e = binarySearch(entries,0,sizeofentries,phoneNumber,&compareByNumber);
                if(e){
                    printf("%25s,%25s,%25s\n","Name","Phone Number","City");
                    printf("%25s,%25s,%25s\n",e->name,e->phoneNumber,e->city);
                }
                else
                    printf("Not Found\n");
                free(phoneNumber);
                break;
            case 3:
                currentScreen = MAIN_MENU;
                break;
            default:
                currentScreen = SEARCHING;
                break;
            }
            break;
        case DISPLAY_DATA:
            displayEntries(entries,sizeofentries);
            currentScreen = MAIN_MENU;
            break;
        default:
            appRunning = false;
            break;
        }

    }

    fclose(fptr);
    
}
