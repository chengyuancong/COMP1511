// COMP1511 lecture example
//
// Read numbers until end of input (or a non-number)  is reached
// then print the sum of the numbers
//
// Version 1
//
// A simple program demonstrating
// stopping a while loop
// when scanf fails to read a number e.g. because end-of-input is reached
//
// Andrew Taylor - andrewt@unsw.edu.au
// 23/03/2019
//

#include <stdio.h>

int main(void) {
    int sum, x, numbersRead;

    sum = 0;
    numbersRead = 1;
    printf("Enter numbers, indicate end-of-input with control-D:\n");

    while (numbersRead == 1) {

        // if scanf can read an integer it will place it in x and it will return 1
        // if scanf can't read an integer it will not change x and it will return 0 or -1
        numbersRead = scanf("%d", &x);

        if (numbersRead == 1) {
            sum = sum + x;
        }
    }

    printf("Sum of the numbers is %d\n", sum);
    return 0;
}