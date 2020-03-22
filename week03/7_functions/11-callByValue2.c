// Try and trace through this program and understand
// what gets printed out and why.

#include <stdio.h>

int f(int x); 

int main(void) {
    int  x, y , z;
    x = 1;
    y = 2;
    z = f(y);
    
    printf("x=%d y=%d z=%d\n", x, y, z);
    return 0;
}

  
int f(int x){
    int y; 
    x = x + 1;
    y = 3;
    return x * y;
}
