// Modify this code to calculates the series
// 1/1 + 1/2 + 1/4 + 1/8 + ...
// until it converges to within 10 decimal places


#include <stdio.h>

#define MIN 1.0e-10

int main(void) {
    double sum = 0;
    double i = 1;
    while(1.0/i >= MIN){
        sum = sum + 1.0/i;
        i = i * 2;
    }
    printf("Sum of series is %.20lf\n",sum);
    return 0;
}

