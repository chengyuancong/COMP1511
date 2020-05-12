// A simple program demonstrating overflow
// We tried to fix overflowFix.c it by using long long instead of int
// It helped with the overflow in the original program but long long is still not
// big enough for our new 'reallyReallyBig' variable. 
// So now we are trying unsigned long long. 
// It is still not big enought for our 'reallyReallyBig' variable.

#include <stdio.h>

int main(void) {
    
    unsigned long long big, bigPlus1, bigTimes2, reallyBig;
    unsigned long long reallyReallyBig;
    big = 2147483647;
    bigPlus1 = big + 1;
    bigTimes2 = big * 2;
    reallyBig = bigPlus1 * 2;
    reallyReallyBig = bigPlus1*bigPlus1*bigPlus1;
    printf("big=%llu bigPlus1=%llu\n", big, bigPlus1);
    printf("bigTimes2=%llu ", bigTimes2);
    printf("reallyBig=%llu\n", reallyBig);
    printf("reallyReallyBig=%llu\n", reallyReallyBig);

    return 0;
}