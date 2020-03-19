// Demonstration of using pre and post decrement operators
// They can get confusing when they are used in an expression
// Try to work out what this will print.
// In this subject we recommend only using in isolation
// eg
// x++;   // On their own like this is ok and not confusing
 

#include <stdio.h>



int main(void) {
    int y = 1; 
    int x = 10; 

    printf("%d\n",x++);
    printf("%d\n",++x); 

    //x = x + 5 * y;
    //y = y + 1;
    x += 5 * y++;

    printf("%d\n",x);
    return 0;
}

