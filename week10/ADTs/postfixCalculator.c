//Implements a postfix calculator (see lecture notes to see what that is)
// using a Stack

// To compile to do a syntax check
// dcc -c postfixCalculator.c

// To compile and create a program to run, you need to choose an implementation to compile it with
// For example if you were using an implementation in StackArray.c you would compile like:
// dcc -o postfixCalculator postfixCalculator.c StackArray.c


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
                int num = atoi(&expression[i]);
                while(isdigit(expression[i])){
                    i++;
                }
                stackPush(s,num);
            } else if(isOperator(expression[i])){
                if(stackSize(s) < 2){
                    fprintf(stderr,"Illegal Expression 1\n");
                    stackDestroy(s);
                    return EXIT_FAILURE;
                }
                int num1 = stackPop(s);
                int num2 = stackPop(s);
                int result = 0;
                if(expression[i] == '+'){
                    result = num1+num2;
                } else if (expression[i] == '*'){
                    result = num1*num2;
                } else if (expression[i] == '-'){
                    result = num2-num1;
                } else if (expression[i] == '/'){
                    result = num2/num1;
                } else {
                    fprintf(stderr,"Illegal Expression 2\n");
                    stackDestroy(s);
                    return EXIT_FAILURE;
                }
               
                stackPush(s,result);
                i++;
            } else {
                i++;
            }
        } 
        if(stackSize(s) == 1){
            int answer = stackPop(s);
            printf("%d\n",answer);
        } else {
            fprintf(stderr,"Illegal Expression 3\n");
            stackDestroy(s);
            return EXIT_FAILURE;
        }
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
