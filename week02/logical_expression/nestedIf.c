// A simple program demonstrating the use of scanf
// and nested if statements

#include <stdio.h>

//Do with nested loops
//-101 big negative number
//-100 small negative number
// 101 big positive number
// 100 small positive number

int main(void) {
    int a;
    printf("Enter a: ");
    scanf("%d", &a);

    printf("%d is a ", a);
    if(a < 0){
        if(a < -100){
            printf("big");
        } else {
            printf("small"); 
        }
        printf(" negative"); 
    } else {
        if(a > 100){
            printf("big");
        } else {
            printf("small");
        }
        printf(" positive");
    }
    printf(" number.\n");

    return 0;
}