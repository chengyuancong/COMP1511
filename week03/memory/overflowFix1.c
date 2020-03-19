// A simple program demonstrating overflow
// We tried to fix overflow.c it by using long long instead of int
// It helped with the overflow in the original program but long long is still not
// big enough for our new 'reallyReallyBig' variable

#include <stdio.h>




int main(void) {
    
    long long big, bigPlus1, bigTimes2, reallyBig;
    long long reallyReallyBig;
    big = 2147483647;
    bigPlus1 = big + 1;
    bigTimes2 = big * 2;
    reallyBig = bigPlus1 * 2;
    reallyReallyBig = bigPlus1*bigPlus1*bigPlus1;
    printf("big=%lld bigPlus1=%lld\n", big, bigPlus1);
    printf("bigTimes2=%lld ", bigTimes2);
    printf("reallyBig=%lld\n", reallyBig);
    printf("reallyReallyBig=%lld\n", reallyReallyBig);

    return 0;
}