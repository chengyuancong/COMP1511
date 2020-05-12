//z5285978
#include<stdio.h>
int main(void){
    int sides;
    double rolled;
    printf("Enter the number of sides on your dice: ");
    scanf("%d", &sides);
    printf("Enter the number of dice being rolled: ");
    scanf("%lf", &rolled);
    double max = rolled * sides;
    double average = (max + rolled) / 2;
    if (sides * rolled > 0) {
        printf("Your dice range is %.0lf to %.0lf.\n", rolled, max);
        printf("The average value is %.6lf\n", average);
    } else {
        printf("These dice will not produce a range.\n");
    }
    return 0;
}
       
      