// This code to prompt the user for input instead of hard-coding the argument of 2.
// It keeps repeating until the user enters non-numeric data.

#include <stdio.h>
#include <stdlib.h>

double answer(int x);


int main(void) {
    int value;
    
    printf("Please enter an integer value: ");
    while(scanf("%d",&value) == 1){        
        printf("The answer is %lf\n",answer(value)); 
        printf("Please enter an integer value: ");
    }
    return EXIT_SUCCESS;
}
     
//function definition/implementation
double answer(int x){
    return x * 42;
}


