// Modify feet2metres.c from C_basics lecture code to use a user defined function.  
#include <stdio.h>

#define INCHES_IN_FOOT  12
#define CM_IN_INCH      2.54
#define CM_IN_METRE     100

int main(void) {
    double feet;
    double metres;

    printf("Enter number of feet: ");
    scanf("%lf", &feet);

    metres = feet * INCHES_IN_FOOT * CM_IN_INCH / CM_IN_METRE;

    printf("%.2lf", feet);
    printf(" feet is ");
    printf("%.2lf", metres);
    printf(" metres\n");

    return 0;
}