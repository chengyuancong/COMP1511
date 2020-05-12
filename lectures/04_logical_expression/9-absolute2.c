// Find the absolute value
//
// A simple program demonstrating the use of scanf,
// printf and an if statement
//

#include <stdio.h>

int main(void) {
    double x, absoluteValue;

    printf("Enter number: ");
    scanf("%lf", &x);

    absoluteValue = x;
    if(x < 0){
        absoluteValue = -x; 
    }
    printf("The absolute value of %lf is %lf\n", x, absoluteValue);
    return 0;
}