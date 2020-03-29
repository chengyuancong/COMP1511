// COMP1511 lecture example
//
// Read 42 numbers and then print the sum of the numbers
//
// A simple program demonstrating
// while & scanf
//
// Note for simplicity we are assuming scanf succeeds in reading an integer.
// A robust program would check that scanf returns 1 to indicate an integer read.
//
// Andrew Taylor - andrewt@unsw.edu.au
// 13/03/2019
//

#define N_NUMBERS 42

#include <stdio.h>

int main(void) {
    int x, sum, n;

    sum = 0;
    printf("Enter %d numbers:\n", N_NUMBERS);

    n = 0;
    while (n < N_NUMBERS) {
        scanf("%d", &x);
        sum = sum + x;
        n = n + 1;
    }

    printf("Sum of the numbers is %d\n", sum);
    return 0;
}