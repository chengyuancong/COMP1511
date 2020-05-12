// COMP1511 programming example
// Calculate the mathematical constant pi to 6 decimal places
// by summing the series
//  4 - 4/3 + 4/5 - 4/7 + 4/9 + ...
// Andrew Taylor - andrewt@unsw.edu.au
// 25/03/2019
//

#include <stdio.h>


#define N_SERIES_TERMS 1000000

int main(void) {
    int n;
    double sum;

    n = 0;
    sum = 0;
    while (n < N_SERIES_TERMS) {
        if (n % 2 == 0) {
            sum = sum + 4.0 / (2 * n + 1);
        } else {
            sum = sum - 4.0 / (2 * n + 1);
        }
        n = n + 1;
    }

    printf("4 - 4/3 + 4/5 - 4/7 + 4/9 + ... = %f\n", sum);
    return 0;
}