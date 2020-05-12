// A simple program which reads integers and prints snap
// and exits if the same number is read twice in a row
//
// Note for simplicity we are assuming scanf succeeds in reading an integer.
// A robust program would check that scanf returns 1 to indicate an integer read.
//
// Andrew Taylor - andrewt@unsw.edu.au
// 25/03/2019
//

#include <stdio.h>

int main(void) {
    int n, previousN;

    printf("Enter a number: ");
    scanf("%d", &previousN);

    printf("Enter a number: ");
    scanf("%d", &n);

    while (n != previousN) {
        previousN = n;
        printf("Enter a number: ");
        scanf("%d", &n);
    }

    printf("Snap!\n");
    return 0;
}