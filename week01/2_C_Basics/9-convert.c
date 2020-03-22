// A program to read in an amount of time in hours and convert to minutes

#include <stdio.h>
#define MINS_IN_HOURS 60

int main(void) {
    double hours;
    double minutes;

    printf("Please enter the number of hours: ");
    scanf("%lf",&hours);
    
    minutes = hours * MINS_IN_HOURS;
    printf("That is %.2lf minutes\n",minutes);

    return 0;
}
