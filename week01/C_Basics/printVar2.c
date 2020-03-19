// A simple program demonstrating the use of 
// int variables and printf for ints
// This does exactly the same thing as printVar.c
// but is written in a slightly different way


#include <stdio.h>

int main(void) {
    //You can declare and initialise variables in one step
    int answer = 42;
    int result;
    result = -99;
        
    printf("The answer is %d.\nThe result is %d\n", answer,result);

    return 0;
}