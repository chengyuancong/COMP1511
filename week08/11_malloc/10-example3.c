// Silly example
// #3 using pointers to malloc'ed variables
// Andrew Taylor - andrewt@unsw.edu.au
// 27/3/2019

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *i_pointer = malloc(sizeof (int));
    int *sum_pointer = malloc(sizeof (int));

    *i_pointer = 0;
    *sum_pointer = 0;

    while (*i_pointer < 10) {
        *sum_pointer = *sum_pointer + *i_pointer;
        *i_pointer = *i_pointer + 1;
    }

    printf("%d\n", *sum_pointer); // prints 45

    free(i_pointer);
    free(sum_pointer);
    return 0;
}