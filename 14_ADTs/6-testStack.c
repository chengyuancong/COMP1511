// The Stack ADT interface is in Stack.h and includes all stack related prototyes and typedefs 
// To compile to do a syntax check
// dcc -c testStack.c

// To compile and create a program to run, you need to choose an implementation to compile it with
// For example if you were using an implementation in StackArray.c you would compile like:
// dcc -o testStack testStack.c StackArray.c



#include <stdlib.h>
#include <stdio.h>

#include <assert.h>
#include "Stack.h"

int main(void){
    printf("Testing an empty stack\n");
    Stack s = stackCreate();
    assert(stackSize(s) == 0);
    printf("passed\n");
    
    printf("Pushing 1 item \n");
    stackPush(s,9);
    assert(stackSize(s) == 1);
    int result = stackPop(s);
    assert(result == 9);
    printf("passed\n");
    
    
    printf("Pushing 100 elements onto stack\n");
    //Push MAX_SIZE on check size 
    int i = 0;
    while( i < MAX_SIZE){
        stackPush(s,i);
        assert(stackSize(s) == i+1);
        i++;
    }
    //Pop MAX_SIZE off check value and size
    i = MAX_SIZE-1;
    while ( i >= 0){
        result = stackPop(s);
        assert(result == i);
        assert(stackSize(s) == i);
        i--;
    }
    printf("Passed\n");
    
    return EXIT_SUCCESS;
    //And many more tests...
}

