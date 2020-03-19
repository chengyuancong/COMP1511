// COMP1511 lecture example
//
// A simple program which prints a triangle
//
// Andrew Taylor - andrewt@unsw.edu.au
// 10/04/2019

#include <stdio.h>

#define SIDE_LENGTH 13

int main(void) {
    int row, column;
    row = 0;
    while (row < SIDE_LENGTH) {
        column = 0;
        while (column <= row) {
            printf("*");
            column = column + 1;
        }
        printf("\n");
        row = row + 1;
    }
    return 0;
}