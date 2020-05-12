// Simple example illustrating call by value

#include <stdio.h>
#include <stdlib.h>

void f(int n); 

int main(void) {
    int  n = 5;
    
    f(n);
    
    printf("n=%d\n", n);
    return EXIT_SUCCESS;
}

void f(int n){
    n = 42;    
}