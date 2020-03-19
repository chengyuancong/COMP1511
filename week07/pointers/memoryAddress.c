// Demonstrating the address of & operator
// Showing where variables are stored in relation to each other


// Easier to see memory layout if we use gcc rather than dcc
// gcc -o memoryAddress memoryAddress.c

// ./memoryAddress

#include <stdio.h>

int main(void) {
    //These variables have all been declared and have addresses in memory
    //These variables will all be located next to each other in memory 
    //although there may be small gaps betwen them
    char c;
    int x;
    int y;    
    double z;
    int a[4];    
         
    printf("Address of c is %p\n",&c);
    printf("Address of x is %p\n",&x);
    printf("Address of y is %p\n",&y);
    printf("Address of z is %p\n",&z);    

	//All  array elements are located next to each other in memory
    printf("Address of a    is %p\n", a);
    printf("Address of a[0] is %p\n",&a[0]);
    printf("Address of a[1] is %p\n",&a[1]);
    printf("Address of a[2] is %p\n",&a[2]);
    printf("Address of a[3] is %p\n",&a[3]);
    
    return 0;
}