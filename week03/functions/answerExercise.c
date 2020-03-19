// Modify this code to prompt the user for input instead of hard-coding the argument of 2.
// Keep repeating until the user enters non-numeric data.

#include <stdio.h>

//function prototype
double answer(int x);

int main(void) {
    
    //Calling (using the function);
    printf("answer(2) = %d\n",answer(2));
       
    return 0;
}
     
//function definition/implementation
double answer(int x){
    return x/2.0;
}

