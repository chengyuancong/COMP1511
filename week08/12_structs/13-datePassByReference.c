// Show the use of passing dates by reference to allow reading in the date
// but also returning 1 or 0 to indicated whether the date was successfully
// read in.

#include <stdio.h>
#include <stdlib.h>

#define MAX_DATES 100


typedef struct date Date;

struct date {
    int day;
    int month;
    int year;
};

// 3/5/2017
void printDate(Date d);
int readDate(Date * d);
int readDates(Date dates[],int maxDates);
void printDates(Date dates[], int numDates);


int main(void){
    Date d;
    //Read in one date
    if(readDate(&d) == 1){
        printDate(d);
    } else {
        fprintf(stderr,"That's not a date!\n");
        return EXIT_FAILURE;
    }

    //Read in lots of dates
    Date importantDates[MAX_DATES];
    int numDates = readDates(importantDates, MAX_DATES);
    printDates(importantDates,numDates);
    return EXIT_SUCCESS;
}

void printDate(Date d){
    printf("%d/%d/%d\n",d.day,d.month,d.year);
}

//Returns 1 if it successfully read in a date
//Returns 0 otherwise
//We need to use a pointer, so we can update the actual
//memory of the struct from the main
int readDate(Date * d){
    if ( scanf("%d/%d/%d",&(d->day),&(d->month),&(d->year)) == 3){
        return 1;
    } else {
        return 0;
    }
}

//                          
//Index    0    1   2   3   4 
//. day  |
//.month |
//.year  |
//We can't use the readDate function because it can't return
//the Date and the result of scanf
//We can do something like that by using pointers which
//we will see soon, but for now we read in 
//each date in the array in this function
int readDates(Date dates[],int maxDates){
    int i = 0;
    while ( i < maxDates && readDate(&dates[i]) == 1){
        
        i = i + 1;
    }
    return i;
}

void printDates(Date dates[], int numDates){
    int i = 0;
    while ( i < numDates ){
        printDate(dates[i]);
        i = i + 1;
    }
}
