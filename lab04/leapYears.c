//z5285978
#include<stdio.h>

int isLeapYear(int year);

int main(void){
    int start;
    int finish;
    printf("Enter start year: ");
    int inputStart = scanf("%d", &start);
    if (inputStart != 1) {
        printf("Invalid input\n");
    } else {
        printf("Enter finish year: ");
        int inputFinish = scanf("%d", &finish);
        if (inputFinish != 1) {
            printf("Invalid input\n");
        } else {
            printf("The leap years between %d and %d are: ", start, finish);
            for(int year = start; year <= finish; year ++ ) {
                if (isLeapYear(year) == 1) {
                    printf("%d ", year);
                } 
            }
            printf("\n");
        }
    }
    return 0;
}

int isLeapYear(int year) {    
    if (year % 4 != 0) {
        return 0;
    } else if (year % 100 != 0) {
        return 1;
    } else if (year % 400 != 0) {
        return 0;
    } else {
        return 1;
    }
}

            