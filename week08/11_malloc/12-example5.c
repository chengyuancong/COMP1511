// Silly example #5
// using pointers to variables in another function
// Andrew Taylor - andrewt@unsw.edu.au
// 27/3/2019

#include <stdio.h>
#include <stdlib.h>

void f(int *i_pointer,int *sum_pointer) {
    *i_pointer = 0;
    *sum_pointer = 0;

    while (*i_pointer < 10) {
        *sum_pointer = *sum_pointer + *i_pointer;
        *i_pointer = *i_pointer + 1;
    }

    printf("%d\n", *sum_pointer); // prints 45
}

int main(void) {
    int i, sum;

    f(&i, &sum);

    return 0;
}