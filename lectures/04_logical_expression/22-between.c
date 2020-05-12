// A program demonstrating common mis-use use of relational operators and logical operators
// Author : angf@cse.unsw.edu.au
// Date: March 2017

#include <stdio.h>

// If you wanted to check whether a number was between 0 and 10 you would use
// (x > 0) && (x < 10)
// below shows some common mistakes

int main(void){
    
    // Often beginning students confuse && and ||
    // When we have an expression like (x > 0) || (x < 10) 
    // it will be true for all numbers!!
    int x = 7;
    printf("If x is %d\n",x);               
    printf("(x > 0) && (x < 10) is %d\n",(x > 0) || (x < 10));
    
    x = -3;
    printf("\nIf x is %d\n",x);           
    printf("(x > 0) && (x < 10) is %d\n",(x > 0) || (x < 10));
    
    x = 10;
    printf("\nIf x is %d\n",x);            
    printf("(x > 0) && (x < 10) is %d\n",(x > 0) || (x < 10));
    
    
    // An expression like 0 < x < 10 does not do what you may think
    // It does (0 < x) < 10
    // This will also always be true, as (0 < x) will always be 0 or 1
    // Using dcc we will at least get a warning about this
    x = 7;
    printf("If x is %d\n",x);               
    printf("(x > 0) && (x < 10) is %d\n", 0 < x < 10);
    
    x = -3;
    printf("\nIf x is %d\n",x);           
    printf("(x > 0) && (x < 10) is %d\n",0 < x < 10);
    
    x = 10;
    printf("\nIf x is %d\n",x);            
    printf("(x > 0) && (x < 10) is %d\n",0 < x < 10);
    return 0;
}
