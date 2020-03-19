// A simple program demonstrating int overflow

//Compile and run with dcc as usual. It detects our overflow and stops the 
//program.
//To see what would have happened compile with 
//gcc -Wall -Werror -O -o overflow overflow.c
//and then run ./overflow

#include <stdio.h>


int main(void) {
    
    int big, bigPlus1, bigTimes2, reallyBig;
   
    big = 2147483647;
    bigPlus1 = big + 1;
    bigTimes2 = big * 2;
    reallyBig = bigPlus1 * 2;
    printf("big=%d bigPlus1=%d\n", big, bigPlus1);
    printf("bigTimes2=%d ", bigTimes2);
    printf("reallyBig=%d\n", reallyBig);

    return 0;
}