// A program with bad style. What do you think it does?

#include <stdio.h>


int main(void) {
    double f;
    double m;
    scanf("%lf", &f);
    m = f * 12 * 2.54 / 100;
    printf("%.2lf ", f);
    printf("%.2lf\n", m);
    return 0;
}