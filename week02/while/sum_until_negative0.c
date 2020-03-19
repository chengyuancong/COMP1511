// COMP1511 lecture example
//
// Read numbers until a negative number is read
// then print the sum of the numbers (not including the negative number)
//
// Version 1
//
// A simple program demonstrating
// stopping a while loop
// when a particular value is read by scanf
//
// Note for simplicity we are assuming scanf succeeds in reading an integer.
// A robust program would check that scanf returns 1 to indicate an integer read.
//
// Andrew Taylor - andrewt@unsw.edu.au
// 23/03/2019
//

#include <stdio.h>

int main(void) {
    int x, sum;

    sum = 0;
    x = 0;
    printf("Enter numbers, terminate with a negative number:\n");

    while (x >= 0) {
        scanf("%d", &x);
        if (x > 0) {
            sum = sum + x;
        }
    }

    printf("Sum of the numbers is %d\n", sum);
    return 0;
}