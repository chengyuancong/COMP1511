//z5285978
#include <stdio.h>
#include <math.h>

int main(void){
    
    int length;
    printf("Enter vector length: ");
    scanf("%d", &length);
    
    double vector1[length];
    printf("Enter vector 1: ");
    for (int i = 0; i < length; i++) {
        scanf("%lf", &vector1[i]);
    }
    
    double vector2[length];
    printf("Enter vector 2: ");
    for (int i = 0; i < length; i++) {
        scanf("%lf", &vector2[i]);
    }
    
    double power = 0;
    for (int i = 0; i < length; i++) {
        power = power + pow(vector1[i]-vector2[i], 2);
    }
    
    double distance = sqrt(power);
    
    printf("Euclidean distance =  %06lf\n", distance);
    
    return 0;
}