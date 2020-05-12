// Simple example of using scanf return value to control a loop
// This loop reads in until the user enters a non-integer value
// or until 10 ints have been read in

#include <stdio.h>

#define INPUTS 10

int main(void) {
    int num;
    int counter;
    
    counter = 0;
    while(counter < INPUTS && scanf("%d",&num) == 1){
       printf("I read in %d\n",num);
       counter = counter + 1;
    }
    printf("\nI read in %d inputs\n",counter);
    return 0;
}