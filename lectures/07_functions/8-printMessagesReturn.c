// Simple example of using functions
// This uses return in a void function to terminate the 
// printManyMessages function early under certain conditions
// This could be rewritten using if statements as shown in the commented out 
// implementation of the function.
 


#include <stdio.h>

void printManyMessages(int n);
void printMessages(void);

int main(void) {
    int n;
    printManyMessages(1);
    printf("Repeat this how many times? ");
    scanf("%d", &n);
    printManyMessages(n);
    return 0;
}

// This function demonstrates using a return statement
// to change the flow of control and exit the function
// before it reaches the end. See the alternative version
// below, restructured with the return statement
// Some consider this bad style and prefer the alternative version
// I think it is ok to use sparingly 
void printManyMessages(int n) {
    if(n > 100){
        printf("No way am I printing it that many times!\n");
        return;
    }    
    while (n > 0) {
        printMessages();
        n = n - 1;
    }
    printf("Actually I am starting to feel a little C sick\n");    
}

/*
Alternate version using if statements
void printManyMessages(int n) {
    if(n > 100){
        printf("No way am I printing it that many times!\n");
    } else {
        while (n > 0) {
            printMessages();
            n = n - 1;
        }
        printf("Actually I am starting to feel a little C sickk\n");
    }
}
**/

void printMessages(void) {
    printf("C is good.\n");
    printf("C is great.\n");
    printf("We all love C.\n");    
}