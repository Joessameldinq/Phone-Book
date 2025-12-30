#ifndef DEFINITIONS_H
#define DEFINITIONS_H


// Colors
#define RESET   "\033[0m"
#define BRED    "\033[1;31m"
#define BGREEN  "\033[1;32m"
#define BYELLOW "\033[1;33m"
#define BBLUE   "\033[1;34m"
#define BMAG    "\033[1;35m"
#define BCYAN   "\033[1;36m"
#define BWHITE  "\033[1;37m"

#define MAX_NAME 50
#define MAX_PHONE_NUMBER 15
#define MAX_CITY 50
typedef struct{
    char name[MAX_NAME];
    char phoneNumber[MAX_PHONE_NUMBER];
    char city[MAX_CITY];
}Entry;

#endif