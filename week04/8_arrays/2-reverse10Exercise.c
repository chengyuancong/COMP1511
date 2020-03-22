// Read 10 numbers and print them in reverse order - the hard way
// This approach quickly becomes impractical if you want to read more numbers
// a much better approach is to use an array

// Write a solution using an array instead of 10 variables!
// Modify your solution to check the input read with scanf
// Modify your solution to prompt the user for how many integers they will be entering up to a // 
// maximum of 1000000, instead of always reading in and reversing 10 integers.


#include <stdio.h>

int main(void) {
    int x0, x1, x2, x3, x4,x5,x6,x7,x8,x9,x10;
    printf("Enter 10 numbers: ");
    scanf("%d", &x0);
    scanf("%d", &x1);
    scanf("%d", &x2);
    scanf("%d", &x3);
    scanf("%d", &x4);
    scanf("%d", &x5);
    scanf("%d", &x6);
    scanf("%d", &x7);
    scanf("%d", &x8);
    scanf("%d", &x9);
    printf("Numbers reversed are:\n");
    printf("%d\n", x9);
    printf("%d\n", x8);
    printf("%d\n", x7);
    printf("%d\n", x6);
    printf("%d\n", x5);
    printf("%d\n", x4);
    printf("%d\n", x3);
    printf("%d\n", x2);
    printf("%d\n", x1);
    printf("%d\n", x0);
    return 0;
}