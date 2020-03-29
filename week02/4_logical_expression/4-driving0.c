// A simple program demonstrating an if statement
#define MIN_DRIVING_AGE 18

#include <stdio.h>

int main(void) {
    int age;
  
    printf("Hello enter your age: ");
    scanf("%d", &age);
    
    if(age >=MIN_DRIVING_AGE){
        printf("You are old enough to drive\n");
    } 
    printf("Goodbye\n");

    return 0;
}