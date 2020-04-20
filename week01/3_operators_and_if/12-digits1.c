// A simple program demonstrating the use of scanf
// and if statements with complex conditions

#include <stdio.h>

int main(void) {
    int x;
    printf("Enter x: ");
    scanf("%d", &x);

    printf("%d has ", x);
    
    if ((x < 10) && (x > -10)) {
        printf("1 digit");   
    } else if ((x < 100) && (x > -100)) {
        printf("2 digits");
    } else {
        printf("more than 2 digits");
    }
     
    printf("\n");

    return 0;
}