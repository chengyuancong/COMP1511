// simple examples of using sizeof
// Andrew Taylor - andrewt@unsw.edu.au
// 27/4/2019

#include <stdio.h>

int main(void) {

    printf("sizeof (char) = %lu\n", sizeof (char));
    printf("sizeof (int) = %lu\n",  sizeof (int));
    printf("sizeof (double) = %lu\n", sizeof (double));
    printf("sizeof int[10] = %lu\n", sizeof (int[10]));
    printf("sizeof int * = %lu\n",   sizeof (int *));
    printf("sizeof double * = %lu\n", sizeof (double *));
    printf("sizeof \"hello\" = %lu\n", sizeof "hello");
    printf("sizeof 99 = %lu\n", sizeof 99);    

    return 0;
}