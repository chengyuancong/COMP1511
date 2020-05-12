// A Stack implementation
// This should not need to read or understood by users of the stack.

#include <stdlib.h>
#include <stdio.h>
#include  "Stack.h"


struct stack{
    int items[MAX_SIZE];
    int size;
};

Stack stackCreate(void){
    Stack s = malloc(sizeof (struct stack));
    if(s == NULL){
        fprintf(stderr,"Insufficient Memory\n");
        exit(EXIT_FAILURE);
    }
    s->size = 0;
    return s;
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
    free(s);
}

int stackSize(Stack s){
    return s->size;
}

int stackTop(Stack s){
    if(s->size == 0){
        fprintf(stderr,"Stack empty\n");
        stackDestroy(s);
        exit(EXIT_FAILURE);
    }
    int topIndex = s->size -1;
    int topItem = s->items[topIndex];
    return topItem;
}

int stackPop(Stack s){
    if(s->size == 0){
        fprintf(stderr,"Stack empty\n");
        stackDestroy(s);
        exit(EXIT_FAILURE);
    }
    int topIndex = s->size -1;
    int topItem = s->items[topIndex];
    s->size--;
    return topItem;
}

