// COMP1511 lecture example
//
// A simple program which reads integers and
// and if a composite number is read exists
// printing the factor
//
// Note for simplicity we are assuming scanf succeeds in reading an integer.
// A robust program would check that scanf returns 1 to indicate an integer read.
//
// Andrew Taylor - andrewt@unsw.edu.au
// 10/04/2019

#include <stdio.h>

int main(void) {
    int n, possibleFactor, keepLooping;
    keepLooping = 1;
    while (keepLooping == 1) {
        printf("Enter a number: ");
        scanf("%d", &n);
        possibleFactor = 2;
        while (possibleFactor < n && keepLooping == 1) {
            if (n % possibleFactor == 0) {
                printf("%d is composite %d is a factor\n", n, possibleFactor);
                keepLooping = 0;
            }
            possibleFactor = possibleFactor + 1;
        }
    }
    return 0;
}