// A simple program demonstrating overflow
// double's can represent all the variables here. But eventually double variables will reach a 
// limit too. See overflowDouble.c

#include <stdio.h>

int main(void) {
    
    double big, bigPlus1, bigTimes2, reallyBig;
    double reallyReallyBig;
    big = 2147483647;
    bigPlus1 = big + 1;
    bigTimes2 = big * 2;
    reallyBig = bigPlus1 * 2;
    reallyReallyBig = bigPlus1*bigPlus1*bigPlus1;
    printf("big=%lf bigPlus1=%lf\n", big, bigPlus1);
    printf("bigTimes2=%lf ", bigTimes2);
    printf("reallyBig=%lf\n", reallyBig);
    printf("reallyReallyBig=%lf\n", reallyReallyBig);

    return 0;
}