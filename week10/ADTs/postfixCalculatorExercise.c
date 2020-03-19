//Implements a postfix calculator (see lecture notes to see what that is)
// using a Stack

// To compile to do a syntax check
// dcc -c postfixCalculatorExercise.c

// To compile and create a program to run, you need to choose an implementation to compile it with
// For example if you were using an implementation in StackArray.c you would compile like:
// dcc -o postfixCalculatorExercise postfixCalculatorExercise.c StackArray.c


#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "Stack.h"

#define MAX_LEN 100
#define FALSE 0
#define TRUE 1

int isOperator(char c);

int main(int argc, char * argv[]){
    char expression[MAX_LEN];
    Stack s = stackCreate();

    if(fgets(expression,MAX_LEN,stdin) != NULL){
        int i = 0;    
        while(expression[i] != '\0' && expression[i] != '\n'){
            if(isdigit(expression[i])){
                 //TODO
            } else if(isOperator(expression[i])){
                 //TODO
                i++;
            } else {
                i++;
            }
        } 
        //TODO
    }

    stackDestroy(s);
    return EXIT_SUCCESS;
}

int isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/'){
        return TRUE;
    } else {
        return FALSE;
    }
}
