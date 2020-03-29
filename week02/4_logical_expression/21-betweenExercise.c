// A program demonstrating common mis-use use of relational operators and logical operators
// Author: A.Finlayson@unswglobal.unsw.edu.au
// Date: 7/01/2019

#include <stdio.h>

// Which statement will check whether a number is between (but not including) 0 and 10.

int main(void){
    int x;
    scanf("%d",&x);
    printf("%d\n",(x > 0) || (x < 10));
    printf("%d\n",(x > 0) && (x < 10));    
    printf("%d\n",0 < x < 10);
    return 0;
}
