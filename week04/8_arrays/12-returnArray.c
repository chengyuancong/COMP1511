// An example to demonstrate that you can't return an array
// from a function. Instead you can pass one in and fill it
// with values!

#include <stdio.h>

#define SIZE 3


//You can't return an array from a function
//int[] foo(void);

//You can instead pass in an array and modify its values!
void foo(int nums[]);

int main(void) {

    int a[SIZE];
    foo(a);
    printf("%d %d %d\n",a[0],a[1],a[2]);

    return 0;
}

//Instead of returning an array
//pass in an array and then fill it with values!
void foo(int nums[]){
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;
}

/*
You can't return an array.
As it is not a copy and the array
does not exist once the function has ended
int[] foo(void){
    int nums[] = {1,2,3};
    return nums;
}
*/
