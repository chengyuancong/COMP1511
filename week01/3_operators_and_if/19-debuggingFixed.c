// A simple program demonstrating fixing terrible style and errors with if 
// statements from debugging.c

#include <stdio.h>

//Fix the style
//Identify the errors
//Fix the errors
int main(void) {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    
    printf("Happy Birthday. You are %d \n", age);
    if (age < 0) {        
        printf("You are a liar\n");
    } else {
        
        if (age == 100) {
            printf("Happy Birthday from the Queen!\n");
        } else if(age >= 18){
            printf("Now you can vote!\n");
        } else {
            printf("You are a minor\n");
        }
    }
     
    return 0;
}