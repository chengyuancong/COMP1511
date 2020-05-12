// Different ways to initialise an array

//Uncomment out the different lines that initialise the 
//nums array and confirm that printing the array
//would give the results you expect


//Try running after compiling with these different options
//gcc -Wall -Werror -O -o arrayDemo2 arrayDemo2.c
//dcc -o arrayDemo2 arrayDemo2.c
//dcc --valgrind -o arrayDemo2 arrayDemo2.c

#include <stdio.h>

#define SIZE_ARRAY 3


int main(void) {
    int nums[SIZE_ARRAY];
    //int nums[] = {4,2,5};
    //int nums[SIZE_ARRAY] = {0};
    //int nums[SIZE_ARRAY] = {3,99};
    int i;
    
    
    i = 0;
    while(i < SIZE_ARRAY){
       printf("%d\n", nums[i]);
       i = i + 1;
    }
       
    return 0;
}