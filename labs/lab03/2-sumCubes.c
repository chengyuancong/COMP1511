//z5285978
#include<stdio.h>

int main(void){
    int cubes = 1;
    printf(" k  cubes\n");
    printf("\n");
    
    int loopCounter = 1;
    while (loopCounter <= 20) {
        printf("%2d  %5d\n", loopCounter, cubes);
        cubes = cubes + loopCounter * loopCounter * loopCounter;
        loopCounter = loopCounter + 1;
    }
    return 0;
}