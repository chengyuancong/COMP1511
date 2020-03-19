// A programming example that prints out
// whether an integer is divisible by 2 
// and whether an integer is divisible by 3

#include <stdio.h>

int main(void) {
    int num;
    printf("Enter an integer: ");
    scanf("%d",&num);
    printf("%d\n", num);
    
    if(num%2== 0 && num%3 == 0){
       printf("%d is divisible by 2\n", num);
       printf("%d is divisible by 3\n", num);
    } else if( num%2 == 0){
        printf("%d is divisible by 2\n", num);
    } else if(num%3 == 0){
       printf("%d is divisible by 3\n", num);
    } 
        
    return 0;
}