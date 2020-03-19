// COMP1511 programming example
// Calculate the mathematical constant e by summing the series
// 1 + 1/(1*2) + 1/(1*2*3) + 1/(1*2*3*4)  + ...
// http://en.wikipedia.org/wiki/E_%28mathematical_constant%29
//
// Andrew Taylor - andrewt@unsw.edu.au
// 25/03/2019
//

#include <stdio.h>


#define N_SERIES_TERMS 20

int main(void) {
    int n;
    double sum, factorial;

    n = 1;
    sum = 0;
    factorial = 1;
    while (n <= N_SERIES_TERMS) {
        sum = sum + 1.0 / factorial;
        factorial = factorial * n;
        n = n + 1;
    }

    printf("1/1 + 1/1 + 1/(1*2) + 1/(1*2*3) + 1/(1*2*3*4)  + ... + 1/%.0f  = %.12f\n", factorial, sum);
    return 0;
}