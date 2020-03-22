//z5285978
#include<stdio.h>

int main(void){
    int loopCounter = 1;
    int cubes = 1;
    printf(" k  cubes\n");
    printf("\n");
    //cubes
    while (loopCounter <= 20) {
        printf("%2d  %5d\n", loopCounter, cubes);
        loopCounter = loopCounter + 1;
        cubes = cubes + loopCounter * loopCounter * loopCounter;
    }
    return 0;
}