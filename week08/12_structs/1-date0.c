// Demonstrating how to create a simple struct and 
// give each field a value
// Demonstrating the address of & operator and size of with a struct
// Showing where variables are stored in relation to each other

// For best results use
// gcc -o date0 date0.c

// ./date0

#include <stdio.h>

typedef struct date Date;

struct date {
    int day;
    int month;
    int year;
};

int main(void) {
   
    Date d;
    
    d.day = 22;
    d.month = 2;
    d.year = 2019;
    
    printf("%d/%d/%d\n",d.day,d.month,d.year);
      
    //Address of d is the same as the address of d.day
    //These are all next to each other in memory
    printf("Address of d is %p\n",&d);
    printf("Address of d.day is %p\n",&d.day);
    printf("Address of d.month is %p\n",&d.month);
    printf("Address of d.year is %p\n",&d.year);
    
    printf("Size of date is %lu\n",sizeof(struct date));
         
    return 0;
}