// Simple example using local variables
// Andrew Taylor - andrewt@unsw.edu.au
// 27/3/2019

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, sum;

    i = 0;
    sum = 0;

    while (i < 10) {
        sum = sum + i;
        i = i + 1;
    }

    printf("%d\n", sum); // prints 45

    return 0;
}