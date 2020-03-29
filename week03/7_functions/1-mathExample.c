// Simple example of using library functions

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Note: If using gcc you may need the -lm flag
//gcc -Wall -Werror -O -o mathEx mathEx.c -lm

//Try abs with a double
int main(void) {
    int a = -199;
    //abs is in stdlib.h, not maths.h like you would expect
    int result = abs(a);
    
    double b = -199.123;
    //Using abs on a double will result in a compiler warning 
    //(and a truncated answer)or with some compilers, an error. 
    //There is one for double (floating point numbers) we use instead.
    double resultB = fabs(b);
       
    printf("Absolute Value of %d is %d\n",a,result); 
    printf("The square root of 2 is %lf\n",sqrt(2));
    printf("Absolute Value of %lf is %lf\n",b,resultB); 
    
    return 0;
}
