//z5285978
#include<stdio.h>

int main(void){
    int sum = 1;
    printf(" k  sum\n");
    printf("\n");
    
    int loopCounter = 1;
    while (loopCounter <= 20) {
        printf("%2d %4d\n", loopCounter, sum);
        sum = sum + loopCounter;
        loopCounter = loopCounter + 1;
    }
    return 0;
}