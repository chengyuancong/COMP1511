// A simple program demonstrating the use of if statements

#include <stdio.h>

int main(void) {
    int a, b;
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
    if (a > b) {
        printf("%d is greater than %d\n", a, b);
    } else if (a < b) {
        printf("%d is less than %d\n", a, b);
    } else {
        printf("%d is equal to %d\n", a, b);
    }
    return 0;
}