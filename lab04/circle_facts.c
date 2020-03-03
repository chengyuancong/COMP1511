//z5285978
#include<stdio.h>
#include<math.h>

double area(double radius);
double circumference(double radius);
double diameter(double radius);

int main(void){
    double radius; 
    printf("Enter circle radius: ");
    scanf("%lf", &radius);
    printf("Area          = %06lf\n", area(radius));
    printf("Circumference = %06lf\n", circumference(radius));
    printf("Diameter      = %06lf\n", diameter(radius));
   
    return 0;
}


double area(double radius) {
    return M_PI * radius * radius; 
}

double circumference(double radius) {
    return 2 * M_PI * radius; 
}

double diameter(double radius) {
    return 2 * radius; 
}