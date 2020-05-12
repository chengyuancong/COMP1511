// An example of short circuit boolean expression evaluation

#include <stdio.h>

int main(void) {
    int x;
    printf("Enter x: ");
    scanf("%d", &x);
    //1000/x only gets evaluated if x!= 0.
    //This is handy as 1000/x will give us a divide by 0 error if x is 0
    printf("%d\n",(x != 0) && (1000/x < 10));
   
    return 0;
}