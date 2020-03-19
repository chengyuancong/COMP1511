// A simple program to calculate the area
// of a circle using the math library
/* 
If you are using gcc you will need to compile with the -lm flag eg
gcc -Wall -Werror -O -o circleMath circleMath.c -lm
*/

#include <stdio.h>
#include <math.h>
int main(void) {
   
    double radius;
    double area;
    printf("Please enter the radius: ");
    scanf("%lf",&radius);
    //M_PI is a constant from the math library
    //pow is a function from the maths library 
    //(we are using it to do radius to the power of 2)
    area = M_PI * pow(radius,2); 
     
    printf("The area for radius %lf is %lf\n",radius, area);

    return 0;
}