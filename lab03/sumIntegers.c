//z5285978
#include<stdio.h>

int main(void){
    int loopCounter = 1;
    int sum = 1;
    printf(" k  sum\n");
    printf("\n");

    while (loopCounter <= 20) {
        printf("%2d %4d\n", loopCounter, sum);
        loopCounter = loopCounter + 1;
        sum = loopCounter + sum;
    }
    return 0;
}