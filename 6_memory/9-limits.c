// A program to demonstrate the constants available in limits.h to find
// the max and min values for integer types and how to find the size in bytes
// of different types


#include <stdio.h>
#include <limits.h>

// less /usr/include/limits.h

int  main(void){
   
    printf("ints are stored in %d bytes\n",sizeof (int));
    printf("long longs are stored in %d bytes\n",sizeof (long long));

    printf("The biggest integer is            %d\n",INT_MAX);
    printf("The smallest integer is           %d\n",INT_MIN);
    printf("The biggest long long is          %lld\n",LLONG_MAX);
    printf("The biggest unsigned long long is %llu\n",ULLONG_MAX);
   
    return 0;
}