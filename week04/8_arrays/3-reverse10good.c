// Read 10 numbers and print them in reverse order
 
// Note for simplicity we are assuming scanf succeeds in reading an integer.
// A robust program would check that scanf returns 1 to indicate an integer read.
// The constants 4 & 5 below would be better replaced with a #deine

#include <stdio.h>

int main(void) {
    int x[5], i, j;
    printf("Enter 10 numbers: ");
    i = 0;
    while (i < 10) {
        scanf("%d", &x[i]);
        i = i + 1;
    }
    printf("Numbers reversed are:\n");
    j = 9;
    while (j >= 0) {
        printf("%d\n", x[j]);
        j = j - 1;
    }
    return 0;
}