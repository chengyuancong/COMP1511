// Print the result of an integer division checking for divide by 0

#include <stdio.h>

int main(void) {
    int x, y;

    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);

    //TODO Print an error instead of doing if we would get a divide by 0 error
    printf("x/y is %d\n",x/y);
    
    
    return 0;
}