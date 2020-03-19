// Demonstration of a user defined function with a return value
#include <stdio.h>

int f(int n);

int main(void) {
    int n = 1;    
     
    //n = f(1) + 10
    //n = 6 + 10  
    //n = 16            
    n = f(n) + 10;
    printf("%d\n",n);
       
    return 0;
}

// input is 1
int f(int n){
    return (n + 5); //returns 6
}

