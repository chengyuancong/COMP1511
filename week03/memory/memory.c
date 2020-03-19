// A simple program demonstrating how to determine the size and the address 
// of variables in memory

#include <stdio.h>

int main(void) {
    
    int x = 99;
    int y = -1;
    double z = 57.2;
    

    printf("The value of x is %d\n",x); 
    printf("The address of x is %p\n",&x);  
    printf("The size of x is %d\n",sizeof x);  

    printf("The value of y is %d\n",y); 
    printf("The address of y is %p\n",&y);  
    printf("The size of y is %d\n",sizeof y);  


    printf("The value of z is %lf\n",z); 
    printf("The address of z is %p\n",&z);  
    printf("The size of z is %d\n",sizeof z);
    return 0;
}