// Exercise in reading code
// Try to understand and work out what this code would do
// Then run to see if you are correct.

#include <stdio.h>

#define SIZE 10

int main(void) {
    int numbers[] = {1,2,3,4,5,6,7,8,9,10};
    int i;
    
    i = 0; 
    while (i*2 < SIZE ) {
        printf("%d\n",numbers[i*2]); 
        i = i + 1;
    }
   
    return 0;
}