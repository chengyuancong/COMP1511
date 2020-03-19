// A simple program demonstrating terrible style and errors with if statements
// Fix the style, identify the errors, fix the errors

#include <stdio.h>


int main(void) {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Happy Birthday. You are %d \n", age);
    if (age <= 0) {        
 printf("You are a liar\n");
    } else {
    if (age == 100) {
    printf("Happy Birthday from the Queen!\n");
    } else 
    if(age = 18){
               printf("Now you can vote!\n");
           }
        
       printf("You are a minor\n");
                                 }
    

    return 0;
}