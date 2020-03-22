/*

Run at CSE like this

gcc invalid3.c -o invalid3
./invalid3
I will never be printed.
argc was 1

*/
#include <stdio.h>
#include <stdlib.h>

void f(void);

int main(int argc, char *argv[]) {

    f();

    if (argc > 0) {
        printf("I should always be printed.\n");
    }

    if (argc <= 0) {
        printf("I should never be printed.\n");
    }

    printf("argc was %d\n", argc);
    return 0;
}


void f(void) {
    int a[10];

    // function f has it return address on the stack
    // the call of function f from main should return to
    // the next statement which is:  if (argc > 0)
    //
    // with gcc at CSE  f's return address is stored where a[14] would be
    //
    // so changing a[14] changes where the function returns
    //
    // adding 24 to a[14] happens to cause it to return several statements later
    // at the printf("I should never be printed.\n");
    
    a[14] += 24;
}
