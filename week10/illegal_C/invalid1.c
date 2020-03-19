/*

Run at CSE like this

gcc invalid1.c -o invalid1
./invalid1

*/

// written by andrewt@cse.unsw.edu.au as a COMP1511 lecture example

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i;
    int a[10];
    printf("i is at address %p\n", &i);
    printf("a[0] is at address %p\n", &a[0]);
    printf("a[9] is at address %p\n", &a[9]);
    printf("a[10] would be stored at address %p\n", &a[10]);

    // loop writes to a[10] .. a[11] which don't exist -
    // but with gcc on cse machines
    // i would be stored where a[11] is stored

    for (i = 0; i <= 11; i++) {
        a[i] = 0;
    }

    return 0;
}