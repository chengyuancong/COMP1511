// Simple example of using void functions
 

#include <stdio.h>

void printManyMessages(int n);
void printMessages(void);

int main(void) {
    int n;
    printManyMessages(1);
    printf("Repeat this how many times? ");
    scanf("%d", &n);
    printManyMessages(n);
    return 0;
}

void printManyMessages(int n) {
    while (n > 0) {
        printMessages();
        n = n - 1;
    }
    printf("Actually I am starting to feel a little C sick\n");
}

void printMessages(void) {
    printf("C is good.\n");
    printf("C is great.\n");
    printf("We all love C.\n");    
}