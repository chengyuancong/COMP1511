// Demonstrate approximate representation of reals
// For example value 0.1 can not be precisely represented as a real


#include <stdio.h>

int main(void) {
    double a, b;
    a = 0.1;
    b = 1 - (a + a + a + a + a + a + a + a + a + a);
    printf("%.20lf\n", b);

    double x = 0.1;   
    printf("%.20lf\n",x);
   
    double y = 0.00000005;
    printf("%.20lf\n",y);
    double z = 999999999999999.00000005;
    printf("%.20lf\n",z);

    return 0;
}