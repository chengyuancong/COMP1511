// A simple program demonstrating the use of scanf
// Try running the program and typing illegal input 
// such as hello to see what happens

#include <stdio.h>

int main(void) {
    int x;
    double y;

    printf("Enter an int then a double : ");
    scanf("%d %lf",&x,&y);
    
    printf("You entered %d %lf\n", x,y);
    return 0;
}