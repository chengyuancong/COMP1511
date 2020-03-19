// A program demonstrating the use of logical  operators

#include <stdio.h>
    
int main(void){
    int x = 7;
    printf("If x is %d\n",x);               
    printf("(x > 0) && (x < 10) is %d\n",(x > 0) && (x < 10));
    
    x = -3;
    printf("\nIf x is %d\n",x);           
    printf("(x > 0) && (x < 10) is %d\n",(x > 0) && (x < 10));
    
    x = 10;
    printf("\nIf x is %d\n",x);            
    printf("(x > 0) && (x < 10) is %d\n",(x > 0) && (x < 10));
    
   
    return 0;
}
