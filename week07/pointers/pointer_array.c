// Simple example illustrating use of pointers
// with array elements
// Andrew Taylor - andrewt@unsw.edu.au

#include <stdio.h>


int main(void) {
    int nums[7] = {5,6,7,8,9,10,11};

    int *n = &nums[3];
    printf("n[0]=%d n[1]=%d n[2]=%d \n", n[0], n[1], n[2]);

    char string[12] = "Hello World";
    char *s = &string[6];
    printf("string = %s\n", string);
    printf("s = %s\n", s);
    printf("&string[9] = %s\n", &string[9]);

    s = &string[2];
    s[2] = '\0';     // equivalent to string[4] = '\0'
    printf("string = %s\n", string);
    printf("s = %s\n", s);

    return 0;
}