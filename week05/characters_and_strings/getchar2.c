// getchar reads in newline characters and whitespace
// sometimes we want to read them in and discard them
// This relies on us knowing the format that data will be entered.

#include <stdio.h>

int main(void) {
    int c1,c2;

    printf("Please enter first character:\n");
    c1 = getchar(); 
    getchar(); //discard the newline
    printf("Please enter second character:\n");
    c2 = getchar();
    printf("First %c\nSecond: %c\n", c1, c2);
    return 0;
}