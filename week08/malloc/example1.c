// Silly example #1
// using pointers to local variables
// Andrew Taylor - andrewt@unsw.edu.au
// 27/3/2019

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, sum;

    int *i_pointer = &i;
    int *sum_pointer = &sum;

    *i_pointer = 0;
    *sum_pointer = 0;

    while (*i_pointer < 10) {
        *sum_pointer = *sum_pointer + *i_pointer;
        *i_pointer = *i_pointer + 1;
    }

    printf("%d\n", *sum_pointer); // prints 45

    return 0;
}