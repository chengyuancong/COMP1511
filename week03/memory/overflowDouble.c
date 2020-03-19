// A simple program demonstrating overflow
// Even double will reach its limits when the numbers get bigger
// What happens in this example? 

// try with gcc and then dcc

#include <stdio.h>
#include <math.h>

int main(void) {
    
    double big, bigp1, bigt2, reallyBig;
   
    big = 2147483647;
    
    bigp1 = big + 1;
    bigt2 = big * 2;
    reallyBig = bigp1 * 2;
    printf("big=%.20lf bigp1=%.20lf\n", big, bigp1);
    printf("bigt2=%.20lf ", bigt2);
    printf("reallyBig=%.20lf\n", reallyBig);
    double reallyReallyBig = pow(reallyBig,31);
    double reallyReallyBigger = pow(reallyBig,32);
    printf("reallyReallyBig %lf\n",reallyReallyBig);
    printf("reallyReallyBigger %lf\n",reallyReallyBigger);
    
    return 0;
}