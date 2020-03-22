// This program is split into more than 1 file. 
// The main function is in this file
// The Stack ADT interface is in Stack.h and includes all stack related prototyes and typedefs 
// To compile to do a syntax check
// dcc -c stackDemo stackDemo.c

// To compile and create a program to run, you need to choose an implementation to compile it with
// For example if you were using an implementation in StackArray.c you would compile like:
// dcc -o stackDemo stackDemo.c StackArray.c

// If instead you were using an implementation in StackList.c you would compile like:
// dcc -o stackDemo stackDemo.c StackList.c

#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

int main(int argc, char * argv[]){
    Stack s;
    s = stackCreate();   
    stackPush(s, 10);
    stackPush(s, 11);
    stackPush(s, 12);
    printf("%d\n", stackSize(s)); // prints 3
    printf("%d\n", stackTop(s)); // prints 12
    printf("%d\n", stackPop(s)); // prints 12
    printf("%d\n", stackPop(s)); // prints 11
    printf("%d\n", stackPop(s)); // prints 10
    printf("%d\n", stackPop(s)); // Should fail
    stackDestroy(s);
    return EXIT_SUCCESS;
}

