//z5285978
#include <stdio.h>

void sort3(double *x, double *y, double *z);

int main(int argc, char *argv[]) {
    double x, y, z;
    scanf("%lf %lf %lf", &x, &y, &z);
    sort3(&x, &y, &z);
    printf("%lf %lf %lf\n", x, y, z);
    return 0;
}

void sort3(double *x, double *y, double *z) {
    double tmp;
    if (*x > *y) {
        tmp = *x;
        *x = *y;
        *y = tmp;
    } 
    if (*x > *z) {
        tmp = *x;
        *x = *z;
        *z = tmp;
    }
    if (*y > *z) {  
        tmp = *y;
        *y = *z;
        *z = tmp;
    } 
}
