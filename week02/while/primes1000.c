// A simple program demonstrating nested while loops
//
// It prints all prime numbers < 10000
//
// Andrew Taylor - andrewt@unsw.edu.au
// 18/03/2019
//

#include <stdio.h>

int main(void) {
    int n, possibleFactor, nFactors;
    // loop through numbers 1..1000
    n = 1;
    while (n < 1000) {
        // loop through numbers 1..n counting factors
        possibleFactor = 1;
        nFactors = 0;
        while (possibleFactor <= n) {
            if (n % possibleFactor == 0) {
                nFactors = nFactors + 1;
            }
            possibleFactor = possibleFactor + 1;
        }
        if (nFactors <= 2) {
            printf("%d is prime\n", n);
        }
        n = n + 1;
    }
    return 0;
}