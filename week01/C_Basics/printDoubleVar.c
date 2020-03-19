// A simple demonstration of printing double variables

#include <stdio.h>

int main(void) {

    double answer;
    double anotherAnswer = -99;
    answer = 42.83199;
    // %.3lf prints a double variable to 3 decimal places.
    printf("Answers are %.3lf %lf\n",answer,anotherAnswer);
    
    return 0;
}