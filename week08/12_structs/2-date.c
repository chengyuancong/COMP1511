//An example of defining a simple date struct
//and passing structs into a function
//and returning a struct from a function
//Dates are read and printed in the following format day/month/year

#include <stdio.h>
#include <stdlib.h>


typedef struct date Date;

struct date {
    int day;
    int month;
    int year;
};


void printDate(Date d);
Date readDate(void);

int main(void){
    Date d = readDate();
    
    printDate(d);
    return EXIT_SUCCESS;
}

// 3/5/2017
void printDate(Date d){
    printf("%d/%d/%d\n",d.day,d.month,d.year);
}

//3/5/2017
Date readDate(void){
    Date d;
    if(scanf("%d/%d/%d",&(d.day),&(d.month),&(d.year)) != 3){
       fprintf(stderr,"Error: date in wrong format\n");
       exit(EXIT_FAILURE);
    }
    return d;
}