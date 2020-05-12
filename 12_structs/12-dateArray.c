// Reads in and prints out up to 100 dates in the format of
// day/month/year eg. 2/4/1980

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
Date readDate(void);
int readDates(Date dates[],int maxDates);
void printDates(Date dates[], int numDates);


int main(void){
    Date importantDates[MAX_DATES];
    printf("Enter up to %d dates in the form d/m/y\n",MAX_DATES);
    int numDates = readDates(importantDates, MAX_DATES);
    printDates(importantDates,numDates);
    return EXIT_SUCCESS;
}

void printDate(Date d){
    printf("%d/%d/%d\n",d.day,d.month,d.year);
}

//3/5/2017
Date readDate(void){
    Date d;
    if(scanf("%d/%d/%d",&(d.day),
                        &(d.month),
                        &(d.year)) != 3){
       fprintf(stderr,"Error: date in wrong format\n");
       exit(EXIT_FAILURE);
    }
    return d;
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
    while ( i < maxDates && 
            scanf("%d/%d/%d",&(dates[i].day),
                        &(dates[i].month),
                        &(dates[i].year)) == 3){
        
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
