// A simple program to calculate the area
// of a circle without using the math library


#include <stdio.h>

#define PI 3.14159

int main(void) {
   
    double radius;
    double area;
    printf("Please enter the radius: ");
    scanf("%lf",&radius);
    area = PI * radius * radius;
     
    printf("The area for radius %lf is %lf\n",radius, area);
    return 0;
}