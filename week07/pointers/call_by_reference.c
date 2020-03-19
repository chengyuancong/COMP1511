// Simple example illustrating use of pointers
// to return values from a function
// Andrew Taylor - andrewt@unsw.edu.au

#include <stdio.h>

void powers(double x, double *square, double *cube) {
    *square = x * x;
    *cube = x * x * x;
}

int main(void) {
    double s, c;

    powers(42, &s, &c);

    printf("42^2 = %lf\n", s);
    printf("42^3 = %lf\n", c);
    return 0;
}