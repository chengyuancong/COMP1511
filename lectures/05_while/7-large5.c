// Read 5 numbers and print the largest
// Andrew Taylor - andrewt@unsw.edu.au
//
// Note for simplicity we are assuming scanf succeeds in reading an integer.
// A robust program would check that scanf returns 1 to indicate an integer read.
//
// 27/03/2019

#include <stdio.h>

#define N_NUMBERS 5

int main(void) {
    int howManyNumbers, number, maximum;
    scanf("%d", &maximum);
    howManyNumbers = 1;
    while (howManyNumbers < N_NUMBERS) {
        scanf("%d", &number);
        if (number > maximum) {
            maximum = number;
        }
        howManyNumbers = howManyNumbers + 1;
    }
    printf("Largest is %d\n", maximum);
    return 0;
}