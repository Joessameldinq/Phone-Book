
#include "../include/helpers.h"
#include "../include/definitions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void clearScreen() {
// #ifdef _WIN32
//     system("cls");
// #else
//     system("clear");
// #endif
}
void displayEntries(Entry entries[], int size) {

    printf("\n");

    // Top border
    printf("%s┏━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━┓%s\n",
           BBLUE, RESET);

    // Header row
    printf("%s┃ %-4s ┃ %-30s ┃ %-20s ┃ %-25s ┃%s\n",
           BYELLOW, "No.", "Name", "Phone Number", "City", RESET);

    // Header separator
    printf("%s┣━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━┫%s\n",
           BBLUE, RESET);

    // Table body
    for (int i = 0; i < size; i++) {
        printf("┃ %-4d ┃ %s%-30s%s ┃ %s%-20s%s ┃ %s%-25s%s ┃\n",
               i + 1,
               BGREEN, entries[i].name, RESET,
               BCYAN, entries[i].phoneNumber, RESET,
               BWHITE, entries[i].city, RESET);
    }

    // Bottom border
    printf("%s┗━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━┛%s\n",
           BBLUE, RESET);
}
int mainMenu() {
    clearScreen();
    int choice = 0;

    printf("\n \t\t\t\t%s=============================%s\n", BBLUE, RESET);
    printf(" \t\t\t\t%s        MAIN  MENU          %s\n", BYELLOW, RESET);
    printf(" \t\t\t\t%s=============================%s\n", BBLUE, RESET);

    printf(" \t\t\t\t%s[1]%s Sort Data\n", BGREEN, RESET);
    printf(" \t\t\t\t%s[2]%s Search Data\n", BCYAN, RESET);
    printf(" \t\t\t\t%s[3]%s View Current Content\n", BMAG, RESET);
    printf(" \t\t\t\t%s[4]%s Exit\n", BRED, RESET);

    printf("\n \t\t\t\t%sEnter your choice: %s", BWHITE, RESET);
    scanf("%d", &choice);

    return choice;
}


int sortingAlgorithmMenu() {
    int choice = 0;
    clearScreen();

    printf("\n\t\t\t\t%s=============================%s\n", BBLUE, RESET);
    printf("\t\t\t\t%s     SORTING  ALGORITHM     %s\n", BYELLOW, RESET);
    printf("\t\t\t\t%s=============================%s\n", BBLUE, RESET);

    printf("\t\t\t\t%s[1]%s Merge Sort\n", BGREEN, RESET);
    printf("\t\t\t\t%s[2]%s Quick Sort\n", BCYAN, RESET);
    printf("\t\t\t\t%s[3]%s Back to Main Menu\n", BRED, RESET);

    printf("\n\t\t\t\t%sEnter your choice: %s", BWHITE, RESET);
    scanf("%d", &choice);

    return choice;
}
int sortFieldMenu() {
    int choice = 0;
    clearScreen();

    printf("\n\t\t\t\t%s=============================%s\n", BBLUE, RESET);
    printf("\t\t\t\t%s        SORT  BY            %s\n", BYELLOW, RESET);
    printf("\t\t\t\t%s=============================%s\n", BBLUE, RESET);

    printf("\t\t\t\t%s[1]%s Name\n", BGREEN, RESET);
    printf("\t\t\t\t%s[2]%s City\n", BCYAN, RESET);
    printf("\t\t\t\t%s[3]%s Phone Number\n", BMAG, RESET);
    printf("\t\t\t\t%s[4]%s Back\n", BRED, RESET);

    printf("\n\t\t\t\t%sEnter your choice: %s", BWHITE, RESET);
    scanf("%d", &choice);

    return choice;
}
int searchFieldMenu() {
    int choice = 0;
    clearScreen();

    printf("\n\t\t\t\t%s=============================%s\n", BBLUE, RESET);
    printf("\t\t\t\t%s        SEARCH  BY          %s\n", BYELLOW, RESET);
    printf("\t\t\t\t%s=============================%s\n", BBLUE, RESET);

    printf("\t\t\t\t%s[1]%s Name\n", BGREEN, RESET);
    printf("\t\t\t\t%s[2]%s Phone Number\n", BMAG, RESET);
    printf("\t\t\t\t%s[3]%s Back\n", BRED, RESET);

    printf("\n\t\t\t\t%sEnter your choice: %s", BWHITE, RESET);
    scanf("%d", &choice);

    return choice;
}
char* readString() {
    char *string = malloc(50);
    if (!string) return NULL;
    printf("Press enter to continue..\n");
    (void)getchar();
    if (fgets(string, 50, stdin) == NULL) {
        free(string);
        return NULL;
    }

    // remove trailing newline if present
    string[strcspn(string, "\n")] = '\0';

    return string;
}