// A comparison between passing primitive values like ints or doubles, 
// which are passed by value/copy and arrays are passed by reference in C
 

#include <stdio.h>

void f(int nums[], int size);
void f2(int x);

int main(void){
    int nums[5] = {0};
    int x = 3; 
    f2(x);
    printf("%d\n",x);  //What will this print?

    f(nums,5);

    int i = 0;
    while(i < 5){
        printf("%d\n",nums[i]); //What will this print?
        i = i + 1;
    }
    return 0;
}

void f(int nums[], int size){
    nums[0] = 42; 
}

void f2(int x){
    x = 42;
}