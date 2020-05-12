// A Stack implementation
// This should not need to read or understood by users of the stack. 
// Exercise: Implement the incomplete functions

#include <stdlib.h>
#include <stdio.h>
#include  "Stack.h"

struct stack{
    int items[MAX_SIZE];
    int size;  
};


Stack stackCreate(void){
    // TODO  
    return NULL;
}

void stackPush(Stack s, int item){
    int index = s->size;
    if(s->size < MAX_SIZE){
        s->items[index] = item;
        s->size++;
    } else {
        fprintf(stderr,"Stack full\n");
        stackDestroy(s);
        exit(EXIT_FAILURE);
    }
}

void stackDestroy(Stack s){
    //TODO
}

int stackSize(Stack s){
    //TODO
    return -1;
}

int stackTop(Stack s){
    //TODO
    return -1;
}

int stackPop(Stack s){
    //TODO
    return -1;
}

