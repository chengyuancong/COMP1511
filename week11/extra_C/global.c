//An example of global variables
//We discourage the use of these in CP1511
//Try and work out what gets printed in this 
//example
 
#include <stdio.h>

int x;

void f(int j) ;
void g(int x);

int main(void) {
    printf("%d\n", x); 
    f(99);
    printf("%d\n", x); 
    x = 1;
    printf("%d\n", x); 
    g(17);
    printf("%d\n", x); 

    return 0;
}

void f(int j) {
    x = j;
}

void g(int x){
   x = x + 1;
}
