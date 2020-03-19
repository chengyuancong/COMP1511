//An example of what can happen when you go beyond the bounds of an array
//Hint: bad things can happen!


#include <stdio.h>

//See what happens with these different compiler options
//gcc -o
//gcc -Wall -Werror -O -o
//dcc -o
//dcc --valgrind -o

//Enter index 10 (just out of bounds)
//Enter index 100   (way out of bounds)
//Enter index 10000 (way way out of bounds)


int main(void) {
    int index;
    int testArray[10] = {0,1,2,3,4,5,6,7,8,9};
    int var = 99;
  
    printf("Var = %d\n",var);
    printf ("Enter an array index between 0 and 9\n");
    scanf ("%d", &index);
    
    printf ("testArray[%d]=%d\n",index, testArray[index]);
    testArray[index] = -1;
    printf("Var = %d\n",var);
   
    return 0;
}