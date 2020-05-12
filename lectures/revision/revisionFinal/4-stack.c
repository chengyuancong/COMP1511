//Given a string as a command line argument
//Print it in reverse using a stack
//Assume maximum length of string is 100 characters

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 100

 
int main(int argc, char * argv[]){
    char stack[MAX];
    int stackSize = 0;
    assert(argc > 1);
    int i = 0;
    while( argv[1][i] != '\0'){
         //push onto stack
         stack[stackSize] =  argv[1][i];
         stackSize++;
         i++;
    }

    while( stackSize > 0){
        //pop from stack
        stackSize--;
        printf("%c",stack[stackSize]);
    }    
    printf("\n");

    return 0;
}


 