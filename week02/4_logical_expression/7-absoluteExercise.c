// Find the absolute value of x without using the Math.h library


#include <stdio.h>

int main(void) {
    double x, absoluteValue;

    printf("Enter number: ");
    scanf("%lf", &x);


    printf("The absolute value of %lf is %lf\n", x, absoluteValue);
    return 0;
}