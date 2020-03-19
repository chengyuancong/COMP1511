// A simple program demonstrating the use of scanf
// to sum 2 numbers

#include <stdio.h>

int main(void) {
    int x, y, sum;
    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);
    sum = x + y;
    printf("%d + %d = %d\n", x, y, sum);
    return 0;
}