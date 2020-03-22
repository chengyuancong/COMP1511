// Demonstration of diffent types of user defined functions
 
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void printStuff(void);
void printNumber(int n);
int getNumber(void);
int doCalculation(int n);


int main(void) {
    srand(time(NULL));
    int result;
    printStuff();
    printNumber(5);
    result = getNumber();
    printf("result %d\n",result);    
    result = doCalculation(99);
    printf("result %d\n",result);
    return 0;
}

void printStuff(void){
    printf("Hooray!\n");
   
}

void printNumber(int n){
    int i = n;
    while(i > 0){
        printf("%d ",i);
        i = i - 1;
    }
    printf("Blast off!\n");   
}

//return a random number between 0 and 9
int getNumber(void){   
    return rand()%10;
}

int doCalculation(int n){
    return n+1;
}