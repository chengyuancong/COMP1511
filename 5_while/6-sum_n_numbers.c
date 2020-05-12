// COMP1511 lecture example
//
// Read n numbers and then print the sum of the numbers
//
// A simple program demonstrating
// while & scanf
//
// Note for simplicity we are assuming scanf succeeds in reading an integer.
// A robust program would check that scanf returns 1 to indicate an integer read.
//
// Andrew Taylor - andrewt@unsw.edu.au
// 23/03/2019
//

#include <stdio.h>

int main(void) {
    int x, sum, n, nNumbers;

    sum = 0;
    printf("How many numbers do you wish to sum: ");
    scanf("%d", &nNumbers);
    printf("Enter %d numbers:\n", nNumbers);

    n = 0;
    while (n < nNumbers) {
        scanf("%d", &x);
        sum = sum + x;
        n = n + 1;
    }

    printf("Sum of the numbers is %d\n", sum);
    return 0;
}