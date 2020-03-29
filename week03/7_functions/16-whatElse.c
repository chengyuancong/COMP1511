//Try to work out what this does without running it first

#include <stdio.h>
#include <stdlib.h>

void f1(void);
void f2(void);
void f3(void);
void f4(void);

int main(void){
    printf("This ");
    f1(); 
    printf("how ");
    f4(); 
    printf("work!\n");    
    return 0;
}

void f1(void){
    printf("is ");
    f2();
    printf("know ");
}

void f2(void){
     printf("to ");
     f3();
     printf("you ");
}

void f3(void){
    printf("ensure ");
}

void f4(void){
    printf("functions ");
}