// A program to calculate the sum of two integers.
// Sample solution.

#include <stdio.h>

int main(void) {
    // Make two integers to store the scanned-in values.
    int x, y;

    // Get the two numbers from the user.
    printf("Please enter two integers: ");
    scanf("%d %d", &x, &y);

    // Calculate the sum of the two numbers, and store it in a variable.
    int sum = x + y;

    // Print out the sum of the two numbers.
    printf("%d + %d = %d\n", x, y, sum);

    return 0;
}