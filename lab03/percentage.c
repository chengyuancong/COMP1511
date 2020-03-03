//z5285978
#include<stdio.h>
int main(void){

    int marks;
    double awarded;
    printf("Enter the total number of marks in the exam: ");
    scanf("%d", &marks);
    printf("Enter the number of marks the student was awarded: ");
    scanf("%lf", &awarded);
    double scored = (awarded / marks) * 100;
    printf("The student scored %.0lf%% in this exam.\n", scored);
    
    return 0;
}
    