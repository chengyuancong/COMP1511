// A simple program demonstrating an if statement


#include <stdio.h>

int main(void) {
    int age;
  
    printf("Hello enter your age: ");
    scanf("%d", &age);
    
    if(age >=MIN_DRIVING_AGE){
        printf("You are old enough to drive\n");
    } else {
        printf("Sorry you are not old enough to drive\n");
    }
    printf("Goodbye\n");

    return 0;
}