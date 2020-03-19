// Exercise in reading code
// Try to understand and work out what this code would do
// Then run to see if you are correct.


#include <stdio.h>

#define SIZE 10

int main(void) {
    int numbers[SIZE];
    int i;
    
    i = 0;
    while (i < SIZE ) {
       numbers[i] = i * i ;
       i = i + 1;
    }
   
   
    i = 0;
    while (i < SIZE ) {
       printf("%d\n",numbers[i]);
       i = i + 1;
    }
    return 0;
}