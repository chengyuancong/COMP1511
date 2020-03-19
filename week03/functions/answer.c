// Demonstration creating and using a user defined function

// Demonstration: 
// What happens if we remove the prototype? What about if we move the function implementation to the top?
// What happens if the prototype does not match the implementation?
// What happens if we forget to call the function?
// Try to call the function again with an argument of 10

#include <stdio.h>

//function prototype
double answer(int x);

int main(void) {
    
    //Calling (using the function);
    printf("answer(2) = %lf\n",answer(2));
       
    return 0;
}
     
//function definition/implementation
double answer(int x){
    return x/2.0;
}

