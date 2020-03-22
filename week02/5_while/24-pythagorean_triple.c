// COMP1511 lecture example
//
// A simple program which searches for Pythagorean triples
// integers which form form the sides of a right triangle
// http://en.wikipedia.org/wiki/Pythagorean_triple
// Andrew Taylor - andrewt@unsw.edu.au
//
// 10/04/2019

#include <stdio.h>

#define N 100

int main(void) {
    int x, y, z;
    x = 1;
    while (x < N) {
        y = 1;
        while (y <= N) {
            z = 1;
            while (z <= N) {
                if (x * x + y * y == z * z) {
                    printf("%d^2 + %d^2 = %d^2\n", x, y, z);
                }
                z = z + 1;
            }
            y = y + 1;
        }
        x = x + 1;
    }
    return 0;
}