//Given a string as a command line argument
//Print it in reverse using a stack ADT
//Assume maximum length of string is 100 characters

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 100

typedef struct stack * Stack;

struct stack{
    char items[MAX];
    int size;
};

Stack createStack(void);
void destroyStack(Stack s);
char popStack(Stack s);
void pushStack(Stack s, char item);
int  sizeStack(Stack s);

int main(int argc, char * argv[]){
    Stack s = createStack();
    assert(argc > 1);
    int i = 0;
    while( argv[1][i] != '\0'){
         pushStack(s,argv[1][i]);
         i++;
    }

    while( sizeStack(s) > 0){
        printf("%c",popStack(s));
    }    
    printf("\n");
    destroyStack(s);

    return 0;
}


Stack createStack(void){
    Stack s = malloc(sizeof(struct stack));
    s->size = 0;
    return s;
}

void destroyStack(Stack s){
    free(s);
}

char popStack(Stack s){
    assert(s->size != 0);
    s->size--;
    return s->items[s->size];
}

void pushStack(Stack s, char item){
    assert(s->size != MAX);
    s->items[s->size] = item;
    s->size++;
}

int sizeStack(Stack s){
    return s->size;
}
