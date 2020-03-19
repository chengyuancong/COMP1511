// In theory this is infinite recursion. In practice the program will crash. Why?
#include <stdio.h>

void message(void);

int main(void){
    message();
    return EXIT_FAILURE;
}

void message(void){   
    printf("Good Evening.");
    printf("Good Evening. Are you happy with your phone plan?");
    message();
}
