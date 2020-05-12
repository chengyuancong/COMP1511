#ifndef QUEUE_STACK_H
#define QUEUE_STACK_H

#endif //QUEUE_STACK_H

// A Stack ADT Interface
// If a user wants to write a program using this stack, they should only need to look at this file
// to understand how to use the stack


#define MAX_SIZE 100


//Note: To use the stack we do not need to know what is in the struct stack.
typedef struct stack * Stack;


Stack stackCreate(void);
void stackPush(Stack s, int item);
int stackTop(Stack s);
int stackPop(Stack s);
int stackSize(Stack s);
void stackDestroy(Stack s);
